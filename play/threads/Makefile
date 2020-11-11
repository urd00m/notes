CC=gcc -pthread -m64 -Wall -O3 -g

all: pthread-ex parallel-sum-ex

pthread-ex : pthread-ex.c
	$(CC) pthread-ex.c -o pthread-ex

parallel-sum-ex : parallel-sum-ex.c
	$(CC) parallel-sum-ex.c -o parallel-sum-ex

clean: 
	rm -f pthread-ex parallel-sum-ex



