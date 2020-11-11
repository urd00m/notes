#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // for gettimeofday

#define ARRAY_SIZE (1024*1024*256)

static double 
time_array (int * a, int stride) 
{
    int i, offset, tmp;
    struct timeval t1, t2;
    double el;

    // start timing run
    gettimeofday(&t1, NULL);

    /* notice what's going on in this for loop. if stride is 1, we access the array like this:
     *
     * [| | | | | | | | | | | | | | | | ]  (every element sequentially)
     *
     * if the stride is 4, we access it like this:
     *
     * [|       |       |       |       ] <--- 1st run through
     * [ |        |       |       |     ] <--- 2nd run through
     * ...
     * [      |       |        |      | ] <--- final run through
     *
     * Think about the spatial and temporal locality of these access patterns!
     */
    for (offset = 0; offset < stride; offset++) {
        for (i = 0; i < ARRAY_SIZE; i += stride) {
            tmp = a[i+offset];
        }
    }

    // end timig run
    gettimeofday(&t2, NULL);

    el = (t2.tv_sec - t1.tv_sec) * 1000.0;
    el += (t2.tv_usec - t1.tv_usec) / 1000.0;

    return el;
}


int 
main (int argc, char * argv[]) 
{
    int stride;
    int * a;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <stride>\n", argv[0]);
        exit(0);
    }

    stride = atoi(argv[1]);

    // allocate this many elements of size 1, and initialize to zero
    a = (int*)calloc(ARRAY_SIZE*sizeof(int), 1);
    
    printf("Stride: %d Time: %3.2fms\n", stride, time_array(a, stride));

    return 0;
}
