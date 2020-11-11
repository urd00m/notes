#!/usr/bin/perl -w

use IO::Handle;

$#ARGV==0 or die "usage: plot_mountain.pl <file>\n";

$file=shift;

(-e $file) or die "$file does not exist" ;

print "Plotting memory mountain - appears in new window\n";

open(G, "|gnuplot");
G->autoflush(1);
print G "set logscale x\nset logscale y\nset dgrid3d 32,32\nset hidden3d\n";
print G "set xlabel \"Working Set Size (bytes)\"\n";
print G "set ylabel \"Stride Size (doubles)\"\n";
print G "set zlabel \"Bandwidth (MB/s)\"\n";
print G "splot \"$file\" with lines\n";

print "Hit enter to finish\n";
<STDIN>;
