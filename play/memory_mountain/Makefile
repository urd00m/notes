CC = gcc
CFLAGS = -Wall -m32 -O2 -D__i386__
#CFLAGS = -Wall -O2 -D__i386__
#CFLAGS = -Wall -m64 -O2 

mountain: mountain.c fcyc2.c clock.c
	$(CC) $(CFLAGS) -o mountain mountain.c fcyc2.c clock.c 

clean:
	rm -f mountain *.o *~


