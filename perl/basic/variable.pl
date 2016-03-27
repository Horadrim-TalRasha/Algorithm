#!/usr/bin/perl


use strict;
use warnings;

# 1. 
#undef is equal to null in PHP and None in python
my $undef = undef;
print $undef;

#this is still a uninitialized variable
my $undef2;
print $undef2;

#append the string
print "Hello "." World"."\n";



# 2. Boolean
# undef
# 0
# ""
# "0"
# will be treated as false

####         print "4G" + "4H";  # will a warning
print "4G" eq "4H";  # correct



# 3. Array
my @array = (
             1,
             2,
             "string"
            );

print @array;
print "\n";


# 4. Hash
# hash could contains a hash
my %hash = (
            "a" => "apple",
            "b" => "banana",
            "h" => {              #   contains a hash
                    "c" => "cancer",
                    "g" => "gemini",
                   },
           );

print $hash{"h"}{"c"};
print "\n";


# 5. Context
# my $scalar = ("Alpha", "Beta", "Gamma", "Pie"); # $scalar will be "Pie"
# my @array = "Mendeleev"; is equal to 'my @array = ("Mendeleev");'
my $scal = ("Alpha", "Beta", "Gamma", "Pie");
print $scal;
print "\n";

my @array_2 = ("Alpha", "Beta", "Goo");
my $scalar = @array_2;
print $scalar;
print "\n";
