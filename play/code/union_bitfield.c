#include <stdio.h>

void print_float(float input)
{
  union {
    unsigned u;
    float f;
    struct {
        unsigned frac:23;
        unsigned exp:8;
        unsigned sign:1;
    } bits;
  } v;
  
  v.f = input;
  printf("The size of v is %d bytes\n",sizeof(v));
  printf("floating point value %f's bytes are 0x%x, and it has sign %u exp %u frac 0x%x\n", v.f, v.u, v.bits.sign, v.bits.exp,v.bits.frac);
}

int main()
{
  print_float(-1.0);
}

