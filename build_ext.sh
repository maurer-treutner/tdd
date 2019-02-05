#!/bin/sh
#
# Build external tools
#

# Exit script on error
set -e
# Uncomment when debugging script
set -x

projectroot=$(pwd)
extbuilddir=$projectroot/ext/build
prefixdir=$projectroot/prefix

mkdir -p $extbuilddir
mkdir -p $prefixdir

cd $projectroot/ext/build && cmake -DINSTALL_PATH=$prefixdir ..
cd $projectroot/ext/build && cmake --build .