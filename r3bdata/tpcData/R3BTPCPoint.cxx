// -------------------------------------------------------------------------
// -----                      R3BTPCPoint source file                  -----
// -------------------------------------------------------------------------

#include "R3BTPCPoint.h"

#include <iostream>

using std::cout;
using std::endl;
using std::flush;


// -----   Default constructor   -------------------------------------------
R3BTPCPoint::R3BTPCPoint()
  : FairMCPoint(),
  fX_out(0.), fY_out(0.), fZ_out(0.),
  fPx_out(0.), fPy_out(0.), fPz_out(0.){
}
// -------------------------------------------------------------------------


// -----   Destructor   ----------------------------------------------------
R3BTPCPoint::~R3BTPCPoint() { }
// -------------------------------------------------------------------------

// -----   Public method Print   -------------------------------------------
void R3BTPCPoint::Print(const Option_t* opt) const {
  cout << "-I- R3BTPCPoint: STS Point for track " << fTrackID 
       << " in detector " << fDetectorID << endl;
  cout << "    Position (" << fX << ", " << fY << ", " << fZ
       << ") cm" << endl;
  cout << "    Momentum (" << fPx << ", " << fPy << ", " << fPz
       << ") GeV" << endl;
  cout << "    Time " << fTime << " ns,  Length " << fLength 
       << " cm,  Energy loss " << fELoss*1.0e06 << " keV" << endl;
}
// -------------------------------------------------------------------------



// -----   Point x coordinate from linear extrapolation   ------------------
Double_t R3BTPCPoint::GetX(Double_t z) const {
  //  cout << fZ << " " << z << " " << fZ_out << endl;
  if ( (fZ_out-z)*(fZ-z) >= 0. ) return (fX_out+fX)/2.;
  Double_t dz = fZ_out - fZ;
  return ( fX + (z-fZ) / dz * (fX_out-fX) );
}
// -------------------------------------------------------------------------



// -----   Point y coordinate from linear extrapolation   ------------------
Double_t R3BTPCPoint::GetY(Double_t z) const {
  if ( (fZ_out-z)*(fZ-z) >= 0. ) return (fY_out+fY)/2.;
  Double_t dz = fZ_out - fZ;
  //  if ( TMath::Abs(dz) < 1.e-3 ) return (fY_out+fY)/2.;
  return ( fY + (z-fZ) / dz * (fY_out-fY) );
}
// -------------------------------------------------------------------------



// -----   Public method IsUsable   ----------------------------------------
Bool_t R3BTPCPoint::IsUsable() const {
  Double_t dz = fZ_out - fZ;
  if ( TMath::Abs(dz) < 1.e-4 ) return kFALSE;
  return kTRUE;
}
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------

ClassImp(R3BTPCPoint)
