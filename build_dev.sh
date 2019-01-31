#!/bin/sh
#
# Build project (expects build ext to be executed)
#

# Exit script on error
set -e
# Uncomment when debugging script
set -x

projectroot=$(pwd)
builddir=$projectroot/build
prefixdir=$projectroot/prefix

mkdir -p $builddir

cd $projectroot/build 
cmake -DCMAKE_PREFIX_PATH=$prefixdir ../dev
cmake --build .