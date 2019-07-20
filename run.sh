#!/bin/bash

ROOT=/Users/Andrew/Documents/codingProjects/CPP/dofe

SEQUENCE=$ROOT/sequence
N_IMAGES=66
ORIGINAL_IMAGE=$ROOT/original.png
INTER=$ROOT/temp
OUTPUT_FILE=$ROOT/output.csv
THRESH=20

echo "src/conv_engine \
--sequence $SEQUENCE \
--intermediate $INTER \
--images $N_IMAGES \
--original $ORIGINAL_IMAGE \
--output $OUTPUT_FILE \
--threshold $THRESH" 

src/conv_engine \
  --sequence $SEQUENCE \
  --intermediate $INTER \
  --images $N_IMAGES \
  --original $ORIGINAL_IMAGE \
  --output $OUTPUT_FILE \
  --threshold $THRESH 
