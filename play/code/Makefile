# Here, -O is used to simplify the output and generally make it more
# understandable.  On the other hand, the optimizer hides some things we
# want the students to see.   The volatiles in the source code force
# code not to be optimized away / precomputed.  The no-if-conversion
# optimization flags stop the compiler from using cmovs

CC = gcc -m64 -O -fno-if-conversion -fno-if-conversion2 

all: dataflow ctrlflow datalayout array array_surprising struct union_bitfield functions recursion infinite_recursion attackme dot_prod_vec dot_prod_novec


dataflow: dataflow.c
	$(CC) dataflow.c -o dataflow
	$(CC) -c dataflow.c -o dataflow.o
	$(CC) -S dataflow.c

ctrlflow: ctrlflow.c
	$(CC) ctrlflow.c -o ctrlflow
	$(CC) -c ctrlflow.c -o ctrlflow.o
	$(CC) -S ctrlflow.c

datalayout: datalayout.c
	$(CC) datalayout.c -o datalayout 
	$(CC) -c datalayout.c -o datalayout.o
	$(CC) -S datalayout.c

array: array.c
	$(CC) array.c -o array
	$(CC) -c array.c -o array.o
	$(CC) -S array.c

array_surprising: array_surprising.c
	$(CC) array_surprising.c -o array_surprising
	$(CC) -c array_surprising.c -o array_surprising.o
	$(CC) -S array_surprising.c

struct: struct.c
	$(CC) struct.c -o struct
	$(CC) -c struct.c -o struct.o
	$(CC) -S struct.c

union_bitfield: union_bitfield.c
	$(CC) union_bitfield.c -o union_bitfield
	$(CC) -c union_bitfield.c -o union_bitfield.o
	$(CC) -S datalayout.c

functions: functions.c
	$(CC) functions.c -o functions 
	$(CC) -c functions.c -o functions.o
	$(CC) -S functions.c

recursion: recursion.c
	$(CC) recursion.c -o recursion
	$(CC) -c recursion.c -o recursion.o
	$(CC) -S recursion.c

infinite_recursion: infinite_recursion.c
	$(CC) infinite_recursion.c -o infinite_recursion
	$(CC) -c infinite_recursion.c -o infinite_recursion.o
	$(CC) -S infinite_recursion.c

attackme: attackme.c
	$(CC) attackme.c -o attackme
	$(CC) -c attackme.c -o attackme.o
	$(CC) -S attackme.c

dot_prod_novec: dot_prod.c
	$(CC) dot_prod.c -o dot_prod_novec
	$(CC) -c dot_prod.c -o dot_prod_novec.o
	$(CC) -S dot_prod.c -o dot_prod_novec.s

dot_prod_vec: dot_prod.c
	$(CC) -O2 -ftree-vectorize -msse3 dot_prod.c -o dot_prod_vec
	$(CC) -O2 -ftree-vectorize -msse3 -c dot_prod.c -o dot_prod_vec.o
	$(CC) -O2 -ftree-vectorize -msse3 -S dot_prod.c -o dot_prod_vec.s


clean: 
	rm -f dataflow dataflow.s dataflow.o ctrlflow ctrlflow.s ctrlflow.o array array.s array.o array_surprising array_surprising.s array_surprising.o struct struct.s struct.o datalayout datalayout.s datalayout.o union_bitfield union_bitfield.s union_bitfield.o functions functions.s functions.o recursion recursion.o recursion.s infinite_recursion infinite_recursion.o infinite_recursion.s attackme attackme.o attackme.s dot_prod_novec dot_prod_novec.o dot_prod_novec.s dot_prod_vec dot_prod_vec.o dot_prod_vec.s


