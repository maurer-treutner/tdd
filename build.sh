#!/bin/sh
#
# Build this sample
#

projectroot=$(pwd)
builddir=$projectroot/build
extbuilddir=$projectroot/ext/build
prefixdir=$projectroot/prefix
echo "projectroot= $projectroot"

mkdir -p $extprefix
mkdir -p $prefixdir
mkdir -p $builddir

cd $projectroot/ext/build
cmake -DINSTALL_PATH=$prefixdir ..
cmake --build .

mkdir -p $projectroot/build

cd $projectroot/build 
cmake -DCMAKE_PREFIX_PATH=$prefixdir ../dev 
cmake --build .