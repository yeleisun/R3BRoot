#ifndef R3BTPCHitSim_H
#define R3BTPCHitSim_H
#include "TObject.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TString.h"
#include <vector>

#include "FairMCPoint.h"

class R3BTPCHitSim : public FairMultiLinkedData {

  
public:
  // Default Constructor
  R3BTPCHitSim();
  
  R3BTPCHitSim(const R3BTPCHitSim& hit);
  R3BTPCHitSim& operator=(const R3BTPCHitSim&) { return *this; }

  //Destructor
  ~R3BTPCHitSim();
  bool Print();
  bool PrintTrackStatus();
  
public:

 Int_t          fParentTrackID;//     
 Int_t          fTrackStatus;//     
 Int_t          fTrackID;//     
 Int_t          fZ;                //     
 Int_t          fA;                //     
 Int_t          fPDGCode;          //     
 Int_t          fModuleID;     // module id in R3B
 Int_t          fDetectorID;               // copy number
 TString        fParticleName;     //     
 TString        fVolName;     //     
 TString        fProcessName;      //
 Double_t       fCharge;           //     
 Double_t       fMass;             // MeV 
 Double_t       fKineticEnergy; // MeV
 Double_t       fEnergyDeposit;    // MeV

 TLorentzVector fMomentum;     // GeV
 TLorentzVector fPosition;      // cm
 Double_t       fTrackStep;    //cm
 Double_t       fTrackLength;    //cm
 Double_t       fTime;          // ns
 Bool_t         fIsAccepted;       //

  ClassDef(R3BTPCHitSim, 5)
};

#endif
