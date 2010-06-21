
/////////////////////////////////////////////////////////////
// R3BGeoATof
//
// Class for geometry of HYPCAL
//
/////////////////////////////////////////////////////////////
#include "R3BGeoATof.h"
#include "FairGeoNode.h"

#include <iostream>

using std::cout;
using std::endl;


ClassImp(R3BGeoATof)

R3BGeoATof::R3BGeoATof() {
  // Constructor
  fName="sts";
  maxSectors=0;
  maxModules=99;
}

const char* R3BGeoATof::getModuleName(Int_t m) {
  // Returns the module name of sts number m
  if ( m < 0 ) {
  	cout <<"-E- R3BGeoATof::getModuleName:: Module number "
  	       << m << " not known!" << endl;
	 return "";
	 }
  if ( m < 9 ) sprintf(modName,"calstation0%i",m+1);
  else  sprintf(modName,"calstation%i",m+1);
  return modName;
}

const char* R3BGeoATof::getEleName(Int_t m) {
  // Returns the element name of sts number m
  sprintf(eleName,"cal%i",m+1);
  return eleName;
}
