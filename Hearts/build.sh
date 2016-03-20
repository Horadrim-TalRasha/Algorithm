##--------------- Revision List -----------------------
##   2016-03-20  lichao  create version
##-----------------------------------------------------



#!/bin/sh

set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-../Hearts_build}
BUILD_TYPE=${BUILD_TYPE:-debug}

#  && cmake \
#           -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
#           -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
#           -DCMAKE_BUILD_NO_EXAMPLES=$BUILD_NO_EXAMPLES \
#           $SOURCE_DIR \
#  && make $*

# Use the following command to run all the unit tests
# at the dir $BUILD_DIR/$BUILD_TYPE :
# CTEST_OUTPUT_ON_FAILURE=TRUE make test


# check arguments
while getopts "t:r:" arg
do
    case $arg in
        t) case $OPTARG in
               release|debug) BUILD_TYPE=$OPTARG;;
               *) echo "wrong build type $*"; exit 1
           esac;;
        r) BUILD_DIR="../$OPTARG";;
        *) echo "unkown argument"; exit 1
    esac
done


mkdir -p $BUILD_DIR/$BUILD_TYPE \
  && cd $BUILD_DIR/$BUILD_TYPE \
  && cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
           $SOURCE_DIR \
  && make
