#!/usr/bin/perl 

use IO::Handle;

$#ARGV==3 || die "overflow.pl signed|unsigned xconst ymin ymax\n";

($which, $x, $ymin, $ymax) = @ARGV;

system "./overflow $which $x $ymin $ymax > temp.plot";

open(G, "|gnuplot");
G->autoflush(1);

print G "set xlabel 'y'\nset ylabel '$x+y'\n";
print G "plot 'temp.plot' using 2:3 with linespoints title '$x+y for y=$ymin to $ymax'\n";

print STDOUT "Hit enter to continue\n";

<STDIN>;

