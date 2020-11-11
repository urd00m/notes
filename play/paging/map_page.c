#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>

#define PAGEMAP_ENTRY 8
#define GET_BIT(X,Y) (((X) & ((uint64_t)1<<Y)) >> (Y))
#define GET_OFFSET(X) ((X) & 0xfff)
#define GET_PFN(X) ((X) & 0x7FFFFFFFFFFFFF)
#define PN_TO_PAGE(X) (((X) << 12))
#define PAGE_TO_PN(X) (((X) >> 12))

const int __endian_bit = 1;
#define is_bigendian() ( (*(char*)&__endian_bit) == 0 )


int read_pagemap(int pid, char * path_buf, unsigned long virt_addr, unsigned long num_pages);

int main(int argc, char ** argv)
{
  int pid;
  unsigned long virt_addr; 
  unsigned long num_pages;
  char path_buf [0x100] = {};
  char *end;

  if(argc!=4) {
    printf("usage: map_page process_id|self virtual_addr_hex num_pages\n");
    return -1;
  }
  
  if (!memcmp(argv[1],"self",sizeof("self"))) {
    sprintf(path_buf, "/proc/self/pagemap");
    pid = -1;
  } else {
    pid = strtol(argv[1],&end, 10);
    if (end == argv[1] || *end != '\0' || pid<=0){ 
      printf("PID must be a positive number or 'self'\n");
      return -1;
    }
  }
  
  virt_addr = strtol(argv[2], NULL, 16);
  num_pages = strtol(argv[3],NULL,10);


  if (pid!=-1) {
      sprintf(path_buf, "/proc/%u/pagemap", pid);
  }

  read_pagemap(pid, path_buf, virt_addr, num_pages);
  return 0;
}

int read_pagemap(int pid, char * path_buf, unsigned long virt_addr, unsigned long num_pages)
{
  uint64_t read_val, file_offset;
  FILE * f;
  unsigned long i;
  unsigned long page;
  int c, status;

  f = fopen(path_buf, "rb");
  

  if (!f) {
    printf("Error! Cannot open %s\n", path_buf);
    return -1;
  }

  if (getpagesize()!=4096) { 
    printf("This will only work for page size of 4KB\n");
    return -1;
  }

  for (page=0;page<num_pages; page++, virt_addr+=4096) { 
    
    file_offset = PAGE_TO_PN(virt_addr) * PAGEMAP_ENTRY;
    
    if (pid==-1) { 
      printf("process (self) virtual address 0x%lx => ", virt_addr);
    } else {
      printf("process %d virtual address 0x%lx => ", pid, virt_addr);
    }
    
    status = fseek(f, file_offset, SEEK_SET);
    
    if (status) {
      perror("Failed to do fseek!");
      return -1;
    }
    
    errno = 0;
    read_val = 0;
    unsigned char c_buf[PAGEMAP_ENTRY];
    
    for (i=0; i < PAGEMAP_ENTRY; i++){
      c = getc(f);
      if(c==EOF){
	printf("\nReached end of the file\n");
	return 0;
      }
      if(is_bigendian()) {
	c_buf[i] = c;
      } else {
	c_buf[PAGEMAP_ENTRY - i - 1] = c;
      }
    }
    
    for (i=0; i < PAGEMAP_ENTRY; i++) {
      read_val = (read_val << 8) + c_buf[i];
    }
    
    if (GET_BIT(read_val, 63)) {
      printf("Physical address 0x%llx\n",(unsigned long long) PN_TO_PAGE(GET_PFN(read_val))+GET_OFFSET(virt_addr)); 
    }  else {
      printf("Page is not present\n");
    }
    
    if (GET_BIT(read_val, 62)) {
      printf("Page is swapped\n");
    }
  }
    
  fclose(f);

  return 0;
}
