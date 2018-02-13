#!/bin/bash

export TPCLIBDIR="/home/gpfs/manip/mnt0607/structurenucleaire/ysun/gsi/2018/R3BRoot/r3bdata/tpcData"

rm *.o
rm *.so
rm R3BTPCSetupDict.cxx

rootcint -f R3BTPCSetupDict.cxx      -c R3BTPCSetup.h

make -f GNUmakefileSetup
