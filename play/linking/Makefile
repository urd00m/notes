all: test-static test-dynamic test-cplusplus-static test-cplusplus-dynamic

test-static:	test.o ext.o
	gcc -m64 -static test.o ext.o -o test-static

test-dynamic:	test.o ext.o
	gcc -m64 test.o ext.o -o test-dynamic

test-cplusplus-static: test-cplusplus.o ext-cplusplus.o
	g++ -m64 -static test-cplusplus.o ext-cplusplus.o -o test-cplusplus-static

test-cplusplus-dynamic: test-cplusplus.o ext-cplusplus.o
	g++ -m64 test-cplusplus.o ext-cplusplus.o -o test-cplusplus-dynamic

test.o : test.c
	gcc -m64 -c test.c -o test.o

ext.o : ext.c
	gcc -m64 -c ext.c -o ext.o

test-cplusplus.o : test-cplusplus.cc
	g++ -m64 -c test-cplusplus.cc -o test-cplusplus.o

ext-cplusplus.o : ext-cplusplus.cc
	g++ -m64 -c ext-cplusplus.cc -o ext-cplusplus.o

clean:
	rm *.o test-static test-dynamic test-cplusplus-static test-cplusplus-dynamic

