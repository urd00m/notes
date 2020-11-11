
CFLAGS:=-O2
L1D:=$(shell getconf LEVEL1_DCACHE_LINESIZE)
CC:=gcc
OBJS:= prefetch \
       noprefetch \
       with_branch_hints \
       without_branch_hints 

all: $(OBJS)

prefetch: prefetch.c 
	$(CC) $(CFLAGS) -DUSE_PREFETCH=1 -DL1D_LINESIZE=$(L1D) -o $@ $<

noprefetch: prefetch.c
	$(CC) $(CFLAGS) -DL1D_LINESIZE=$(L1D) -o $@ $<

with_branch_hints: expect.c
	$(CC) -m64 -DUSE_BHINTS -freorder-blocks -o $@ $< -lm

without_branch_hints: expect.c
	$(CC) -m64 -o $@ $< -lm

clean: 
	rm -f $(OBJS)
