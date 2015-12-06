#!/bin/sh


TargetFile=test.xml


##  basic usage
##sed 's/property/properties/' $TargetFile  ## show the modified file content but file was not modified

sed -i 's/property/properties/' $TargetFile ## this cmd will modify file
