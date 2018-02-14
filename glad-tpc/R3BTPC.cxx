#include <iostream>
#include <stdlib.h>

#include "R3BTPC.h"

#include "R3BTPCHitSim.h"

#include "R3BMCStack.h"

#include "FairGeoInterface.h"
#include "FairGeoLoader.h"
#include "FairGeoNode.h"
#include "FairGeoRootBuilder.h"
#include "FairRootManager.h"
#include "FairRuntimeDb.h"
#include "FairRun.h"
#include "FairVolume.h"

#include "TClonesArray.h"
#include "TGeoMCGeometry.h"
#include "TParticle.h"
#include "TVirtualMC.h"
#include "TObjArray.h"
#include "TMCProcess.h"
#include "TGraph.h"

// includes for modeling
#include "TGeoManager.h"
#include "TParticle.h"
#include "TVirtualMC.h"
#include "TVirtualMCStack.h"
#include "TGeoMatrix.h"
#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoPgon.h"
#include "TGeoSphere.h"
#include "TGeoArb8.h"
#include "TGeoCone.h"
#include "TGeoTube.h"
#include "TGeoBoolNode.h"
#include "TGeoCompositeShape.h"

#include "R3BTPCSetup.h"

using std::cout;
using std::cerr;
using std::endl;

#define U_MEV 931.4940954

// -----   Default constructor   -------------------------------------------
R3BTPC::R3BTPC() : R3BDetector("R3BTPC", kTRUE, kTPC)
{

  GetTPCParameters();
  fTPCHitSimCollection = new TClonesArray("R3BTPCHitSim");
  fVerboseLevel = 1;//cout npoint registed

}
// -------------------------------------------------------------------------



// -----   Standard constructor   ------------------------------------------
R3BTPC::R3BTPC(const char* name, Bool_t active)
    : R3BDetector(name, active, kTPC)
{

  GetTPCParameters();
  fTPCHitSimCollection = new TClonesArray("R3BTPCHitSim");
  fVerboseLevel = 1;//cout npoint registed

}
// -------------------------------------------------------------------------

R3BTPC::R3BTPC(const TString& geoFile, const TGeoTranslation& trans, const TGeoRotation& rot)
    : R3BTPC(geoFile, { trans, rot })
{
    GetTPCParameters();
    fTPCHitSimCollection = new TClonesArray("R3BTPCHitSim");
}

R3BTPC::R3BTPC(const TString& geoFile, const TGeoCombiTrans& combi)
    : R3BDetector("R3BTPC", kTPC, geoFile, combi)
{
    GetTPCParameters();
    fTPCHitSimCollection = new TClonesArray("R3BTPCHitSim");
}


// -----   Destructor   ----------------------------------------------------
R3BTPC::~R3BTPC()
{

  if (fTPCHitSimCollection) 
  {
     fTPCHitSimCollection->Delete();
     delete fTPCHitSimCollection;
  }

}
//_____________________
void R3BTPC::FinishRun()
{
   ;
}
// -------------------------------------------------------------------------
void R3BTPC::Initialize()
{
  FairDetector::Initialize();

  LOG(INFO) << "R3BTPC: initialisation" << FairLogger::endl;
  LOG(DEBUG) << "-I- R3BTPC: Vol (McId) def" << FairLogger::endl;

  LOG(INFO) << "R3BTPC: Sci. Vol. (McId) " << gMC->VolId("TPCLog") << FairLogger::endl;

}

//____________________________________________________________
void R3BTPC::SetSpecialPhysicsCuts()
{
    LOG(INFO) << "-I- R3BTPC: Adding customized Physics cut ... " << FairLogger::endl;

    if (gGeoManager)
    {
        TGeoMedium* pmix = gGeoManager->GetMedium("test");
        if (pmix)
        {
            // Setting processes for Gas
            //gMC->Gstpar(pmix->GetId(), "LOSS", 3);
            //gMC->Gstpar(pmix->GetId(), "STRA", 1.0);
            //gMC->Gstpar(pmix->GetId(), "PAIR", 1.0);
            //gMC->Gstpar(pmix->GetId(), "COMP", 1.0);
            //gMC->Gstpar(pmix->GetId(), "PHOT", 1.0);
            //gMC->Gstpar(pmix->GetId(), "ANNI", 1.0);
            //gMC->Gstpar(pmix->GetId(), "BREM", 1.0);
            //gMC->Gstpar(pmix->GetId(), "HADR", 1.0);
            //gMC->Gstpar(pmix->GetId(), "DRAY", 1.0);
            //gMC->Gstpar(pmix->GetId(), "DCAY", 1.0);
            //gMC->Gstpar(pmix->GetId(), "MULS", 1.0);
            //gMC->Gstpar(pmix->GetId(), "RAYL", 1.0);

            // Setting Energy-CutOff for Gas Only, 0.01mm
            Double_t cutE = 1e-6; // GeV-> 1 eV

            LOG(INFO) << "-I- R3BTPC: Medium Id " << pmix->GetId() << " Energy Cut-Off : " << cutE << " GeV" << FairLogger::endl;

            // Si
            gMC->Gstpar(pmix->GetId(), "CUTGAM", cutE); /** gammas (GeV)*/
            gMC->Gstpar(pmix->GetId(), "CUTELE", cutE); /** electrons (GeV)*/
            gMC->Gstpar(pmix->GetId(), "CUTNEU", cutE); /** neutral hadrons (GeV)*/
            gMC->Gstpar(pmix->GetId(), "CUTHAD", cutE); /** charged hadrons (GeV)*/
            gMC->Gstpar(pmix->GetId(), "CUTMUO", cutE); /** muons (GeV)*/
            gMC->Gstpar(pmix->GetId(), "BCUTE", cutE);  /** electron bremsstrahlung (GeV)*/
            gMC->Gstpar(pmix->GetId(), "BCUTM", cutE);  /** muon and hadron bremsstrahlung(GeV)*/
            gMC->Gstpar(pmix->GetId(), "DCUTE", cutE);  /** delta-rays by electrons (GeV)*/
            gMC->Gstpar(pmix->GetId(), "DCUTM", cutE);  /** delta-rays by muons (GeV)*/
            gMC->Gstpar(pmix->GetId(), "PPCUTM", -1.);  /** direct pair production by muons (GeV)*/
        }

    } //!gGeoManager
}



// -----   Public method ProcessHits  --------------------------------------
Bool_t R3BTPC::ProcessHits(FairVolume* vol)
{
    //*******************************************************************************//
    //************************All of the hit in TPC*****************************//
    //*******************************************************************************//

    R3BTPCHitSim ahit;

    ahit.fParticleName = gMC->GetStack()->GetCurrentTrack()->GetName();
    Double_t M_in = gMC->TrackMass()*1000.;//MeV
    ahit.fA = M_in/U_MEV;
    ahit.fZ = gMC->TrackCharge();
    ahit.fCharge = gMC->TrackCharge();
    ahit.fMass = gMC->TrackMass();//GeV
    ahit.fPDGCode = gMC->TrackPid();


    ahit.fVolName = vol->GetName();
    ahit.fModuleID = vol->getModId();//module id, 
    //ahit.fModuleName = vol->getRealName();
    ahit.fDetectorID = Int_t(vol->getCopyNo());//volume copy number
    //ahit.fDetectorID = vol->getMotherId();//mother volume id
    //ahit.fDetectorID = vol->getMotherCopyNo();//mother volume copy no
    
    gMC->TrackPosition(ahit.fPosition);//x,y,z,M, cm and GeV
    gMC->TrackMomentum(ahit.fMomentum);//Px,Py,Pz,E, GeV/c GeV

    ahit.fTime = gMC->TrackTime()*1.0e09;

    ahit.fParentTrackID = gMC->GetStack()->GetCurrentParentTrackNumber();
    ahit.fTrackID = gMC->GetStack()->GetCurrentTrackNumber();
    //____________same result
    //PrimaryParticleID = gMC->GetStack()->GetCurrentTrack()->GetMother(0);

    ahit.fTrackStep = gMC->TrackStep();
    ahit.fTrackLength = gMC->TrackLength();

    ahit.fKineticEnergy =  (gMC->Etot() - gMC->TrackMass()) * 1000.;      //in MeV
    ahit.fEnergyDeposit = gMC->Edep() * 1000.;         //in MeV

    ahit.fTrackStatus = GetTrackStatus(gMC->IsNewTrack(),
    gMC->IsTrackDisappeared(),
    gMC->IsTrackStop(),
    gMC->IsTrackAlive(),
    gMC->IsTrackEntering(),
    gMC->IsTrackExiting(),
    gMC->IsTrackInside(),
    gMC->IsTrackOut());

    ahit.fIsAccepted = kTRUE;

    //_______________only care about primary particle and decayed particle
    if(ahit.fParentTrackID==-1
     ||(ahit.fParentTrackID==0&&ahit.fParticleName!="e-"))
    AddHit(ahit);

    return kTRUE;
}

//____________________________Public method EndOfEvent   -----------------------------------------
void R3BTPC::BeginEvent()
{
;
}
// -----   Public method EndOfEvent   -----------------------------------------
void R3BTPC::EndOfEvent()
{
  if (fVerboseLevel) Print();

  fTPCHitSimCollection->Clear();
  
}
// ----------------------------------------------------------------------------
void R3BTPC::PreTrack()
{
    R3BTPCHitSim ahit;

    ahit.fParticleName = gMC->GetStack()->GetCurrentTrack()->GetName();
    Double_t M_in = gMC->TrackMass()*1000.;//MeV
    ahit.fA = M_in/U_MEV;
    ahit.fZ = gMC->TrackCharge();
    ahit.fCharge = gMC->TrackCharge();
    ahit.fMass = gMC->TrackMass();//GeV
    ahit.fPDGCode = gMC->TrackPid();

    ahit.fVolName = gMC->CurrentVolName();
    //ahit.fVolName = vol->GetName();
    //ahit.fModuleID = vol->getModId();//module id, 
    //ahit.fDetectorID = Int_t(vol->getCopyNo());//volume copy number

    gMC->TrackPosition(ahit.fPosition);//x,y,z,M, cm and GeV
    gMC->TrackMomentum(ahit.fMomentum);//Px,Py,Pz,E, GeV/c GeV

    ahit.fTime = gMC->TrackTime()*1.0e09;

    ahit.fParentTrackID = gMC->GetStack()->GetCurrentParentTrackNumber();
    ahit.fTrackID = gMC->GetStack()->GetCurrentTrackNumber();

    ahit.fTrackStep = gMC->TrackStep();
    ahit.fTrackLength = gMC->TrackLength();

    ahit.fKineticEnergy =  (gMC->Etot() - gMC->TrackMass()) * 1000.;      //in MeV
    ahit.fEnergyDeposit = gMC->Edep() * 1000.;         //in MeV

    if(ahit.fParentTrackID==-1
     ||(ahit.fParentTrackID==0&&ahit.fParticleName!="e-"))
    AddHit(ahit);
}
void R3BTPC::PostTrack()
{

    R3BTPCHitSim ahit;

    ahit.fParticleName = gMC->GetStack()->GetCurrentTrack()->GetName();
    Double_t M_in = gMC->TrackMass()*1000.;//MeV
    ahit.fA = M_in/U_MEV;
    ahit.fZ = gMC->TrackCharge();
    ahit.fCharge = gMC->TrackCharge();
    ahit.fMass = gMC->TrackMass();//GeV
    ahit.fPDGCode = gMC->TrackPid();

    ahit.fVolName = gMC->CurrentVolName();
    //ahit.fVolName = vol->GetName();
    //ahit.fModuleID = vol->getModId();//module id, 
    //ahit.fDetectorID = Int_t(vol->getCopyNo());//volume copy number

    gMC->TrackPosition(ahit.fPosition);//x,y,z,M, cm and GeV
    gMC->TrackMomentum(ahit.fMomentum);//Px,Py,Pz,E, GeV/c GeV

    ahit.fTime = gMC->TrackTime()*1.0e09;

    ahit.fParentTrackID = gMC->GetStack()->GetCurrentParentTrackNumber();
    ahit.fTrackID = gMC->GetStack()->GetCurrentTrackNumber();

    ahit.fTrackStep = gMC->TrackStep();
    ahit.fTrackLength = gMC->TrackLength();

    ahit.fKineticEnergy =  (gMC->Etot() - gMC->TrackMass()) * 1000.;      //in MeV
    ahit.fEnergyDeposit = gMC->Edep() * 1000.;         //in MeV

    if(ahit.fParentTrackID==-1
     ||(ahit.fParentTrackID==0&&ahit.fParticleName!="e-"))
    AddHit(ahit);
}



// -----   Public method Register   -------------------------------------------
void R3BTPC::Register()
{
   /**create a new branch in the output tree
    * *@param name            Name of the branch to create
    * *@param Foldername      Folder name containing this branch (e.g Detector name)
    * *@param obj             Pointer of type TCollection (e.g. TClonesArray of hits, points)
    * *@param toFile          if kTRUE, branch will be saved to the tree*/

///GetNAme() is the Detector name "TPC"
 FairRootManager::Instance()->Register("TPCHitSimCollection", GetName(), 
					fTPCHitSimCollection, kTRUE);

}
// ----------------------------------------------------------------------------



// -----   Public method GetCollection   --------------------------------------
TClonesArray* R3BTPC::GetCollection(Int_t iColl) const
{
  if(iColl == 0) {
    return fTPCHitSimCollection;
  }
  else return NULL;
}
// ----------------------------------------------------------------------------



// -----   Public method Print   ----------------------------------------------
void R3BTPC::Print(Option_t* option) const
{
  Int_t nhits = fTPCHitSimCollection->GetEntriesFast();
  LOG(INFO) << "R3BTPC: " << nhits << " hits registered in this event" 
	    << FairLogger::endl;
}
// ----------------------------------------------------------------------------



// -----   Public method Reset   ----------------------------------------------
void R3BTPC::Reset()
{
  fTPCHitSimCollection->Clear();
}
// ----------------------------------------------------------------------------



// -----   Private method AddHit   --------------------------------------------
Bool_t R3BTPC::AddHit(R3BTPCHitSim& ahit)
{
  TClonesArray& clref = *fTPCHitSimCollection;
  Int_t size = clref.GetEntriesFast();
  new(clref[size]) R3BTPCHitSim(ahit);

  return true;

}

// -----   Public method ConstructGeometry   ----------------------------------
void R3BTPC::ConstructGeometry()
{
  TString fileName = GetGeometryFileName();
  if(fileName.EndsWith(".root")) {
    LOG(INFO) << "Constructing TPC geometry from ROOT file " << fileName.Data() 
	      << FairLogger::endl;
    ConstructRootGeometry();
  } else {
    LOG(FATAL) << "TPC geometry file name is not specified" << FairLogger::endl;
    exit(1);
  }
}

//_________________________________________________________
Bool_t R3BTPC::CheckIfSensitive(std::string name)
{
  LOG(INFO) << "R3BTPC::checksensitive " << name << FairLogger::endl;

//  if(TString(name).Contains("TPC")) {
//    return kTRUE;
//  }
//  return kFALSE;

    return kTRUE;
}
//_____________________________________________
void R3BTPC::GetTPCParameters()
{

  R3BTPCSetup* setup = new R3BTPCSetup(1);


  TargetLength           = setup->TargetLength/2.;//cm
  TargetRadius           = setup->TargetRadius;
  WindowThickness        = setup->WindowThickness/2.;
  ChamberLength          = setup->ChamberLength/2.;
  ChamberInnerRadius     = setup->ChamberInnerRadius; 
  TPCRadiusExt           = setup->TPCRadiusExt; 
  TPCLx                  = setup->TPCLx/2.; 
  TPCLy                  = setup->TPCLy/2.; 
  TPCLz                  = setup->TPCLz/2.; 
  ChamberThickness       = setup->ChamberThickness;
  InnerRohacellThickness = setup->InnerRohacellThickness;
  OuterRohacellThickness = setup->OuterRohacellThickness;
  KaptonThickness        = setup->KaptonThickness;
  TargetAngle            = setup->TargetAngle;//deg
  TargetOffsetX          = setup->TargetOffsetX;//cm
  TargetOffsetY          = setup->TargetOffsetY;//cm
  TargetOffsetZ          = setup->TargetOffsetZ;//cm

  delete setup;

  //TargetAngle            = -14.0;
  //TargetOffsetX          = 0.;
  //TargetOffsetY          = 0.;
  //TargetOffsetZ          = 113.4;

}
Int_t R3BTPC::GetTrackStatus(bool NewTrack,
    bool TrackDisappeared,
    bool TrackStop,
    bool TrackAlive,
    bool TrackEntering,
    bool TrackExiting,
    bool TrackInside,
    bool TrackOut)

{
   int trackstatus = 
      1*TrackOut+10*TrackInside+
      100*TrackExiting+1000*TrackEntering+
      10000*TrackAlive + 100000*TrackStop +
      1000000*TrackDisappeared + 10000000*NewTrack;

   return trackstatus;

}
//________________________________________________

ClassImp(R3BTPC)
