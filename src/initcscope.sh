#!/bin/bash

echo "Finding All Source Files"
echo "------------------------------------------"
find $PWD/ -name '*.cpp' -o -name '*.cc' -o -name '*.h' -o -name '*.hpp' -o -name '*.c' > cscope.files


echo "Building CSCOPE Database"
echo "------------------------------------------"
cscope -R -b -q

echo "Setting path to CSCOPE Database"
echo "------------------------------------------"
export CSCOPE_DB=$PWD/cscope.out
