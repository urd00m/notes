#!/usr/bin/python

import sys

N = 1024*1024*16

x = range(0,N);

s = 0.0

for i in range(0,N) :
    s = s + x[i]

print "summed "+str(N)+" doubles in Python, result "+str(s)
