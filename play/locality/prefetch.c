#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include <stdint.h>

#define ARRAY_SIZE (1024*1024*256)
#define ROWS (1024*1024*16)
#define COLS 16

static float 
do_stuff (void) 
{
	int i;
	float x = 100.0;
	float y = 2.0;

	for (i=0;i<5;i++){
		x += 2*pow(y,2.0);
	}
	return x;
}
	

int 
main ()
{
	int i, j;                     // array indexes
	int linesize = L1D_LINESIZE;  // this is the size of our L1 data cache. We used make to pass it in as a compile-time constant
	int * a;                      // pointer to our array
	uint64_t sum = 0;             // uint64_t just means "unsigned long", i.e. a 64-bit unsigned integer
    struct timeval t1, t2;        // for timing our performance
	double elapsed;				  // also for timing

	// allocate space for our array on the heap
	a = malloc(sizeof(int)*ARRAY_SIZE);

	// clear the array
	memset((void*)a, 0, sizeof(int)*ARRAY_SIZE);

	// seed the random number generator
	srand(time(NULL));

	// initialize the array to random integers
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			*(a+i*COLS+j) = rand();
		}
	}

	// begin timing execution
    gettimeofday(&t1, NULL);

	for (i = 0; i < ROWS; i++) {

		for (j = 0; j < COLS; j++) {
			sum += *(a + i*COLS + j); // this is the same as saying count += a[i][j]
		}

#if defined(USE_PREFETCH)
		// you can find more about this builtin function online, but the 0 means it is going to be a read to 
		// a cache line, the 3 means it will have a lot of temporal locality, meaning it is likely to be used again,
		// so it will try to keep the prefetched data into all levels of cache
		// if you look at the assembly this generates, you will see a 'prefetch' instruction
		__builtin_prefetch((void*)(a+((i+1)*COLS)), 0, 3); // this address is the same as a[i+1][0]
#endif
	}

	// compute how long it took
    gettimeofday(&t2, NULL);
    elapsed= (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;

	printf("Time: %3.2fms\n", elapsed);

	return sum;
}
