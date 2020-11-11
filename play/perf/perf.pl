#!/usr/bin/perl -w

$N=1024*1024*16;

@x = 0..$N;

$s = 0.0;

for ($i=0;$i<$N;$i++) {
    $s += $x[$i];
}

print "summed $N doubles in Perl, result $s\n";
