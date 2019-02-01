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
rm -rf $reportdir/*.xml

cd $projectroot/build 
cmake -DCMAKE_PREFIX_PATH=$prefixdir ../dev -DCTEST_REPORT_PATH=$reportdir
cmake --build .