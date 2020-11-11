#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <stdio.h> /* printf */
#include <stdint.h> /* int types */
#include <string.h> /* memset */

#define ROWS 3
#define COLS 3

typedef unsigned int uint_t;

/* this is an example of real code that uses structs/unions to 
 * set a hardware register. the "value" field is used to set the whole
 * register, the other members of the struct set individual bit fields 
 */
struct vmx_pin_ctrls {
    union {
        uint32_t value;
    struct {
        uint_t ext_int_exit            : 1; /* this is how you access individual bits in a data structure */
        uint_t rsvd1                   : 2;
        uint_t nmi_exit                : 1;
        uint_t rsvd2                   : 1;
        uint_t virt_nmi                : 1;
        uint_t active_preempt_timer    : 1;
        uint_t rsvd3                   : 25;
    } __attribute__((packed));  /* this tells GCC to pack the struct (no padding) */
    } __attribute__((packed)); /* there are three of these because if you use packed in the inner structs, you */
} __attribute__((packed));     /* have to explicitly tell GCC to pack the outer structs as well */


static void  
set_bits (void) {
    struct vmx_pin_ctrls p;

    memset(&p, 0, sizeof(struct vmx_pin_ctrls));
    printf ("pins: 0x%8x\n", p.value);

    p.active_preempt_timer = 1;  /* set one bit field */
    printf ("pins: 0x%8x\n", p.value);

    p.value = 0;   /* set ALL bits to zero */
    printf ("pins: 0x%8x\n", p.value);

}


static int
access_array (void) {
	int arr[ROWS][COLS] = 
		{{1, 2, 3},
		 {4, 5, 6},
		 {7, 8, 9}};

	char * as_char_star = (char*)arr; /* this is doing the same thing as below */
	int * as_int_star = (int*)&arr[0][0];
	int a = 0;
	int b = 0;
	int c = 0;
	int ridx = 1;
	int cidx = 2;

	/* the following all do the same thing! */

	a = arr[ridx][cidx]; /* using row-major access pattern */

	b = *((int*)(as_char_star + ridx*COLS*sizeof(int) + cidx*sizeof(int))); /* byte-sized pointer arithmetic */

	c = *(as_int_star + ridx*COLS + cidx); /* notice how we don't need the sizeof's here (because it's a pointer typed for int) */

	if (!(a == b  && b == c)) {
		return -1;
	}
	
	return 0;
}

int array_surprise()
{
	int A[64];

	printf("A at %p, A[5] at %p, 5[A] at %p\n",A,&(A[5]),&(5[A]));

}

/* these are from the CMU slides */
struct rec {
  int a[3];
  int i;
  struct rec *next;
};

void set_i(struct rec *r, int val)
 {
   r->i = val; /* could also say (*r).i */
 }

int *get_ap(struct rec *r, int idx)
{
  return &r->a[idx]; /* same as *(((int*)r)+idx) */
}

int check_val(struct rec *r, int val) {
  int found = 0;
  while (!found && r) {
    int i = r->i;
    if (r->a[i] == val)
      found = 1;
    else
      r = r->next;
  }
  return found;
}

void set_val(struct rec *r, int val) {
  while (r) {
    int i = r->i;
    r->a[i] = val;
    r = r->next;
  }
}

int main () {

	set_bits();

	if (access_array() < 0) {
		printf("ERROR, they're not all equal\n");
	}

	array_surprise();
}

