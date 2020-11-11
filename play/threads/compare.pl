#!/usr/bin/perl -w

use IO::Handle;

$#ARGV==0 or die "usage: compare.pl vectorlen\n";

$n = shift;

@ps = (1,2,4,8,16,32);

open(FILE, ">_plot.in");

print "numt\tseq\tpar\tspeedup\n";

foreach $p (@ps) {
    $result = `./parallel-sum-ex $p $n`;
    $result =~ /Sequential sum:\s+\S+\s+\((\d+)\s+cycles\)/;
    $seq=$1;
    $result =~ /Parallel sum:\s+\S+\s+\((\d+)\s+cycles\)/;
    $par=$1;
    
    print FILE join("\t",$p,$seq,$par,$seq/$par),"\n";
    print join("\t",$p,$seq,$par,$seq/$par),"\n";

}

close(FILE);

open(GNUPLOT, "| gnuplot");
GNUPLOT->autoflush(1);

print GNUPLOT "plot '_plot.in' using 1:2 title 'sequentual' with linespoints, '_plot.in' using 1:3 title 'parallel' with linespoints\n";


<STDIN>;


	
