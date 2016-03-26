##--------------- Revision List -----------------------
##   2016-03-20  lichao  create version
##   2016-03-21  lichao  add -d option to display build arguments
##   2016-03-26  lichao  add usage in script
##-----------------------------------------------------



#!/bin/sh

set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-../Hearts_build}
BUILD_TYPE=${BUILD_TYPE:-debug}
BUILD_OPTIONS=""


function usage ()
{
    set +x
    echo "USAGE: build.sh -r [ build_directory] -t [debug | release] -d"
    echo "                -r specify building directory which will created at the parent directory"
    echo "                -d display compiling arguments"
    echo "                -t specify build type [release and build]"
    echo "                -h show usage"
}

# check arguments
while getopts "t:r:dh" arg
do
    case $arg in
        t) case $OPTARG in
               release|debug) BUILD_TYPE=$OPTARG;;
               *) echo "wrong build type $*"; exit 1
           esac;;
        r) BUILD_DIR="../$OPTARG";;
        d) BUILD_OPTIONS="-DDISPLAY_BUILD_ARGS=true";;
        h) usage; exit 0;;
        *) echo "unkown argument"; exit 1
    esac
done


mkdir -p $BUILD_DIR/$BUILD_TYPE \
  && cd $BUILD_DIR/$BUILD_TYPE \
  && cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
           $BUILD_OPTIONS \
           $SOURCE_DIR \
  && make
