#!/usr/bin/perl -w

use IO::Handle;

print "Measuring memory mountain - this may take some time\n";

open(MOUNT, "./mountain |");
open(GDATA,">mountain.data");


<MOUNT>;
<MOUNT>;
$s = <MOUNT>;
chomp($s);
$s =~ s/s//g;
@strides = split(/\s+/,$s);
shift(@strides);

while ($l=<MOUNT>) {
  chomp($l);
  ($ws,@m) = split(/\s+/,$l);
  if ($ws =~/(\d+)g/) { 
    $ws = $1 * 1024*1024*1024;
  }
  if ($ws =~/(\d+)m/) { 
    $ws = $1 * 1024*1024;
  }
  if ($ws =~/(\d+)k/) { 
    $ws = $1 * 1024;
  }
  for ($i=0;$i<$#m;$i++) {
    print GDATA join("\t",$ws,$strides[$i],$m[$i]),"\n";
  }
}

print "Done.  Mountain is in mountain.data\n";
