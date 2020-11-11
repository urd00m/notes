all: perf_c perf_cc perf_java.class
	-bash -c "time ./perf_c"
	-bash -c "time ./perf_cc"
	-bash -c "time java perf_java"
	-bash -c "time ./perf.pl"
	-bash -c "time ./perf.py"

perf_c: perf.c
	gcc -O2 perf.c -o perf_c

perf_cc: perf.cc
	g++ -O2 perf.cc -o perf_cc

perf_java.class: perf_java.java
	javac perf_java.java

clean:
	rm -f perf_c perf_cc perf_java.class

