#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
#include <math.h>

#define likely(x)       __builtin_expect((x),1) // branch is likely to be taken
#define unlikely(x)     __builtin_expect((x),0) // branch is unlikely to be taken

#define MB              (1<<20)
#define MB8             (8*MB)
#define __ALIGN_8MB     __attribute__((aligned(MB8)))
#define ITER    		100000000  // how many times will we loop

static void __ALIGN_8MB 
bar (int x, int y) 
{
	x = x* 3;
	y = x << 4;
	return;
}

int 
foo (int x, int y) 
{
	int z;

#if defined(USE_BHINTS)
	if (unlikely(x > y))  {
#else 
	if (x > y) {
#endif
		long w;
		z = x + y;
		z <<=2;
		z = z * z / 3;
		z += 24;
		z << 2 + z;
		z += x + 4;
		z += 2;
		z += 3;
		z += 8;
		z *= 4;
		z >> 4;
		z << 1;
		z >> 2;
		w = (long) z;
		w += 32; 
		w = w * w;
		w = w / 4;
		bar(x,y);
	
		return z;
	} else  {
		float y;
		int i;
		y = 948.0;
		y = sqrt(y);
		y *= y;
		y /= 3.7928938;
		for (i = 0; i < 100; i++) {
			y += sqrt(y);
		}
		return y;
	}
}
	


int main () 
{
	int i;
	int x = 10;   
	int y = 24;
	struct timeval t1, t2;
	double elapsed;
	uint64_t total = 0;

	gettimeofday(&t1, NULL);

	for (i = 0 ; i < ITER; i++) {
		total += foo(x, y);
	}

	gettimeofday(&t2, NULL);
	elapsed = (t2.tv_sec - t1.tv_sec) * 1000000.0;
	elapsed += (t2.tv_usec - t1.tv_usec);
	printf("Time: %3.2fus\n", elapsed/ITER);

	return total;
}
