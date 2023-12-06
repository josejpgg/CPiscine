#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
#print "$y.ox\n";
print "$y()!\n";
#print "$y-+#\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            #print "o";
            print ")";
            #print "+";
        }
        else {
            #print ".";
            print "(";
            #print "-";

        }
    }
    print "\n"; 
}
