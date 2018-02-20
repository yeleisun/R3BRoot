#!/bin/bash

#TPCLIBDIR=$PWD
#export TPCLIBDIR

rm *.o
rm *.so
rm R3BTPCSetupDict.cxx

rootcint -f R3BTPCSetupDict.cxx      -c R3BTPCSetup.h

make -f GNUmakefileSetup
