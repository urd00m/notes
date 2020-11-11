all: test #shared

test : test.cc
	g++ -g test.cc -o test

shared: shared.cc
	g++ -g  --std=c++11 shared.cc -o shared

clean:
	-rm -f test shared

