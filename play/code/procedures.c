#include <stdlib.h>
#include <stdio.h>

// toy program from gdb tutorial

int arr[5] = {0,1,2,3,4};

int toy_main()
{
    int x;
    int y;

    y = 3;
    x = arr[y];

    return x;
}

// CMU code
//
// Pointers

/* Increment value by k */
void incrk(int *ip, int k) {
  *ip += k;
}

/* Compute x + 3 */
int add3(int x) {
  int localx = x;
  incrk(&localx, 3);
  return localx;
}

// Recursion

/* Recursive popcount */
int pcount_r(unsigned x) {
  if (x == 0)
    return 0;
  else
    return
      (x & 1) + pcount_r(x >> 1);
}

// Swapping example

void swap(int* p, int* q)
{
  int t = *p;
  *p = *q;
  *q = t;
}

void swap_l(long* p, long* q)
{
  long t = *p;
  *p = *q;
  *q = t;
}

int course1 = 15213;
int course2 = 18243;

void call_swap() {
  swap(&course1, &course2);
}

int swap_main() {
  printf("Initially: course1 = %d, course2 = %d\n", course1, course2);
  call_swap();
  printf("Finally: course1 = %d, course2 = %d\n", course1, course2);
  return 0;
}

// Switch case

long switch_eg
(long x, long y, long z) {
  long w = 1;
  switch(x) {
  case 1:
    w = y*z;
    break;
  case 2:
    w = y/z;
    /* Fall through */
  case 3:
    w += z;
    break;
  case 5:
  case 6:
    w -= z;
    break;
  default:
    w = 2;
  }
  return w;
}

long sparse_switch_eg
(long x, long y, long z) {
  long w = 1;
  switch(x) {
  case 100:
    w = y*z;
    break;
  case 200:
    w = y/z;
    /* Fall through */
  case 300:
    w += z;
    break;
  case 500:
  case 600:
    w -= z;
    break;
  default:
    w = 2;
  }
  return w;
}

int main(int argc, char *argv[]) {
  long x = atoi(argv[1]);
  long y = atoi(argv[2]);
  long z = atoi(argv[3]);
  long w = switch_eg(x, y, z);
  printf("x = %ld, y = %ld, z = %ld --> %ld\n",
	 x, y, z, w);
  exit(0);
}
