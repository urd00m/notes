#include <math.h>
#include <stdint.h> // definitions of standard integers
#include <stdio.h>  // printf

int array[4] = {2, 1, 0, -1};
unsigned uarray[4] = {2, 1, 0, (unsigned)-1};


void dump_bytes(void *p, int n)
{
  int i;
  unsigned char *pc;

  printf("Memory at %lu (%p) (%d bytes): ", p, p, n);
  pc = (unsigned char *) p;
  for (i=0;i<n;i++) { 
    printf("%02x",pc[i]);
  }
  printf("\n");
}


int print_bits(unsigned x)
{
  int i;
  for (i=0;i<sizeof(x)*8;i++) { 
    printf("%d",(x>>(31-i))&0x1);
  }
}


int bitwise_operators()
{
  int a=0xdeadbeef;
  int b=0x12345678;
  int c;

  printf("Bitwise operators\n\n");

  printf("~ 0x%08x ",a); print_bits(a); printf("\n");
  printf("------------------------------------------------\n");  
  c = ~a;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");

  printf("  0x%08x ",a); print_bits(a); printf("\n");
  printf("& 0x%08x ",b); print_bits(b); printf("\n");
  printf("------------------------------------------------\n");  
  c = a & b;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");

  printf("  0x%08x ",a); print_bits(a); printf("\n");
  printf("| 0x%08x ",b); print_bits(b); printf("\n");
  printf("------------------------------------------------\n");  
  c = a | b;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");

  printf("  0x%08x ",a); print_bits(a); printf("\n");
  printf("^ 0x%08x ",b); print_bits(b); printf("\n");
  printf("------------------------------------------------\n");  
  c = a ^ b;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");


  printf("\n");
}

int shifts()
{
  int a=0xdeadbeef;
  unsigned int b=0xdeadbeef;
  int s = 13; // shift amount
  int c;

  printf("Logical shift operators\n\n");

  printf("  0x%08x (%11u) ",b,b); print_bits(b); printf(" << %d\n",s);
  printf("------------------------------------------------------------------\n");  
  c = b << s;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11u) ",b,b); print_bits(b); printf(" >> %d\n",s);
  printf("------------------------------------------------------------------\n");  
  c = b >> s;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");


  printf("Arithmetic shift operators\n\n");

  printf("  0x%08x (%11d) ",a,a); print_bits(a); printf(" << %d\n",s);
  printf("------------------------------------------------------------------\n");  
  c = a << s;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11d) ",a,a); print_bits(a); printf(" >> %d\n",s);
  printf("------------------------------------------------------------------\n");  
  c = a >> s;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("\n");
}

int logical_operators()
{
  int a=0xdeadbeef;
  int b=0x12345678;
  int c;

  printf("Logical operators\n\n");

  printf("! 0x%08x ",a); print_bits(a); printf("\n");
  printf("------------------------------------------------\n");  
  c = !a;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");

  printf("  0x%08x ",a); print_bits(a); printf("\n");
  printf("&&0x%08x ",b); print_bits(b); printf("\n");
  printf("------------------------------------------------\n");  
  c = a && b;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");

  printf("  0x%08x ",a); print_bits(a); printf("\n");
  printf("||0x%08x ",b); print_bits(b); printf("\n");
  printf("------------------------------------------------\n");  
  c = a || b;
  printf("  0x%08x ",c); print_bits(c); printf("\n\n");

  printf("\n");
}

int unsigned_arithmetic()
{
  unsigned a=0xdeadbeef;
  unsigned b=0x12345678;
  int c;

  printf("Unsigned arithmetic\n\n");

  printf("- 0x%08x (%11u) ",a,a); print_bits(a); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = -a;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11u) ",a,a); print_bits(a); printf("\n");
  printf("+ 0x%08x (%11u) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a + b;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11u) ",a,a); print_bits(a); printf("\n");
  printf("* 0x%08x (%11u) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a * b;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11u) ",a,a); print_bits(a); printf("\n");
  printf("/ 0x%08x (%11u) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a / b;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11u) ",a,a); print_bits(a); printf("\n");
  printf("%% 0x%08x (%11u) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a % b;
  printf("  0x%08x (%11u) ",c,c); print_bits(c); printf("\n\n");

  printf("\n");
}

int signed_arithmetic()
{
  int a=0xdeadbeef;
  int b=0x12345678;
  int c;

  printf("Signed arithmetic\n\n");

  printf("- 0x%08x (%11d) ",a,a); print_bits(a); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = -a;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11d) ",a,a); print_bits(a); printf("\n");
  printf("+ 0x%08x (%11d) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a + b;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11d) ",a,a); print_bits(a); printf("\n");
  printf("* 0x%08x (%11d) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a * b;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11d) ",a,a); print_bits(a); printf("\n");
  printf("/ 0x%08x (%11d) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a / b;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("  0x%08x (%11d) ",a,a); print_bits(a); printf("\n");
  printf("%% 0x%08x (%11d) ",b,b); print_bits(b); printf("\n");
  printf("------------------------------------------------------------------\n");  
  c = a % b;
  printf("  0x%08x (%11d) ",c,c); print_bits(c); printf("\n\n");

  printf("\n");
}

int unsigned_sizes_and_endianness()
{
  unsigned char a=1;  // signed, typically 1 byte
  unsigned short b=1; // signed, typically 2 bytes
  unsigned int c=1;   // signed, typically 4 bytes
  unsigned long long d=1; // signed, typically 8 bytes

  unsigned int *p;         // address width of machine (8 bytes here)

  printf("Unsigned sizes and endianness\n\n");
  
  printf("sizeof(a) = %d value=%u (0x%x)\n", sizeof(a),a,a);
  dump_bytes(&a,sizeof(a));

  printf("sizeof(b) = %d value=%u (0x%x)\n", sizeof(b),b,b);
  dump_bytes(&b,sizeof(b));

  printf("sizeof(c) = %d value=%u (0x%x)\n", sizeof(c),c,c);
  dump_bytes(&c,sizeof(c));

  printf("sizeof(d) = %d value=%llu (0x%llx)\n", sizeof(d),d,d);
  dump_bytes(&d,sizeof(d));

  printf("sizeof(p) = %d value=%lu (0x%lx)\n", sizeof(p),p,p);
  dump_bytes(&p,sizeof(p));

  printf("sizeof(uarray) = %d value=%lu (0x%lx)\n", sizeof(uarray),uarray,uarray);
  dump_bytes(uarray,sizeof(uarray));

  p=uarray;
  printf("sizeof(p) = %d value=%ld (0x%lx)\n", sizeof(p),p,p);
  dump_bytes(&p,sizeof(p));

  c= 0xffffffff;
  printf("sizeof(c) = %d value=%u (0x%x)\n", sizeof(c),c,c);
  dump_bytes(&c,sizeof(c));

  c= 0xfffffffe;;
  printf("sizeof(c) = %d value=%u (0x%x)\n", sizeof(c),c,c);
  dump_bytes(&c,sizeof(c));

  printf("\n");

}

int signed_sizes_and_endianness()
{
  char a=1;  // signed, typically 1 byte
  short b=1; // signed, typically 2 bytes
  int c=1;   // signed, typically 4 bytes
  long long d=1; // signed, typically 8 bytes

  int *p;         // address width of machine (4 bytes here)
  

  printf("Signed sizes and endianness\n\n");

  printf("sizeof(a) = %d value=%d (0x%x)\n", sizeof(a),a,a);
  dump_bytes(&a,sizeof(a));

  printf("sizeof(b) = %d value=%d (0x%x)\n", sizeof(b),b,b);
  dump_bytes(&b,sizeof(b));

  printf("sizeof(c) = %d value=%d (0x%x)\n", sizeof(c),c,c);
  dump_bytes(&c,sizeof(c));

  printf("sizeof(d) = %d value=%lld (0x%llx)\n", sizeof(d),d,d);
  dump_bytes(&d,sizeof(d));

  printf("sizeof(p) = %d value=%ld (0x%lx)\n", sizeof(p),p,p);
  dump_bytes(&p,sizeof(p));

  printf("sizeof(array) = %d value=%ld (0x%lx)\n", sizeof(array),array,array);
  dump_bytes(array,sizeof(array));

  p=array;
  printf("sizeof(p) = %d value=%ld (0x%lx)\n", sizeof(p),p,p);
  dump_bytes(&p,sizeof(p));

  c=-1;
  printf("sizeof(c) = %d value=%d (0x%x)\n", sizeof(c),c,c);
  dump_bytes(&c,sizeof(c));

  c=-2;
  printf("sizeof(c) = %d value=%d (0x%x)\n", sizeof(c),c,c);
  dump_bytes(&c,sizeof(c));

  printf("\n");
}



int main()
{
  bitwise_operators();
  logical_operators();
  shifts();
  unsigned_arithmetic();
  signed_arithmetic();
  unsigned_sizes_and_endianness();
  signed_sizes_and_endianness();
}
