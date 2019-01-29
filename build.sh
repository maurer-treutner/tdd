#!/bin/sh
#
# Build this sample
#

# Exit script on error
set -e
# Uncomment when debugging script
set -x

projectroot=$(pwd)
builddir=$projectroot/build
extbuilddir=$projectroot/ext/build
prefixdir=$projectroot/prefix
echo "projectroot= $projectroot"

mkdir -p $extbuilddir
mkdir -p $prefixdir
mkdir -p $builddir

cd $projectroot/ext/build
cmake -DINSTALL_PATH=$prefixdir ..
cmake --build .

mkdir -p $projectroot/build

cd $projectroot/build 
cmake -DCMAKE_PREFIX_PATH=$prefixdir ../dev
cmake --build .
ctest --verbose
