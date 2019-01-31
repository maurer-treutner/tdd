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
reportdir=$projectroot/reports

mkdir -p $builddir
mkdir -p $reportdir

cd $projectroot/build 
cmake -DCMAKE_PREFIX_PATH=$prefixdir ../dev
cmake --build .