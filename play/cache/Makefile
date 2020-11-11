CC = gcc -m64
EXECS = cache_test mat
OBJS = cache_test.o mat.o
S = cache_test.s mat.s

all: $(EXECS)

cache_test : cache_test.o
	$(CC) $< -o $@

mat : mat.o
	$(CC) $< -o $@

%.o : %.c
	$(CC) -c $< -o $@
	$(CC) -S $<

clean: 
	rm -f $(EXECS) $(OBJS) $(S)


