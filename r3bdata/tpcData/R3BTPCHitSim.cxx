#include "R3BTPCHitSim.h"


R3BTPCHitSim::R3BTPCHitSim()
    :fParentTrackID(-1),
    fTrackStatus(-1),
    fTrackID(-9999),
    fZ(-9999),
    fA(-9999),
    fPDGCode(-9999),
    fModuleID(-9999),
    fDetectorID(-9999),
    fParticleName(""),
    fVolName(""),
    fProcessName(""),
    fCharge(-9999),
    fMass(-9999),
    fKineticEnergy(-9999),
    fEnergyDeposit(-9999),
    fMomentum(-9999, -9999, -9999, -9999),
    fPosition(-9999, -9999, -9999, -9999),
    fTrackStep(0),
    fTrackLength(0),
    fTime(0),
    fIsAccepted(false)
{
   ;
}

R3BTPCHitSim::R3BTPCHitSim(const R3BTPCHitSim& right)
  : FairMultiLinkedData(right),
    fParentTrackID(right.fParentTrackID),
    fTrackStatus(right.fTrackStatus),
    fTrackID(right.fTrackID),
    fZ(right.fZ),
    fA(right.fA),
    fPDGCode(right.fPDGCode),
    fModuleID(right.fModuleID),
    fDetectorID(right.fDetectorID),
    fParticleName(right.fParticleName),
    fVolName(right.fVolName),
    fCharge(right.fCharge),
    fMass(right.fMass),
    fKineticEnergy(right.fKineticEnergy),
    fEnergyDeposit(right.fEnergyDeposit),
    fMomentum(right.fMomentum),
    fPosition(right.fPosition),
    fTrackStep(right.fTrackStep),
    fTrackLength(right.fTrackLength),
    fTime(right.fTime),
    fIsAccepted(right.fIsAccepted)
{
   ;
}

// -----   Destructor   ----------------------------------------------------
R3BTPCHitSim::~R3BTPCHitSim()
{
   ;
}
// -------------------------------------------------------------------------
bool R3BTPCHitSim::Print()
{
     std::cout<<"========="<<
        fParticleName.Data()<<" trackid="<<fTrackID<<
        " ParentTrackID="<<fParentTrackID<<
        " TrackStatus="<<fTrackStatus<<
        "  fZ="<<fZ<<"  fA="<<fA<<
        "  pdg="<<fPDGCode<<
        "  ModuleID="<<fModuleID<<
        "  DetectorID="<<fDetectorID<<
        "  at Vol:"<<fVolName<<
        "  ProcessName:"<<fProcessName<<
        "  charge:"<<fCharge<<
        "  Mass:"<<fMass<<"  GeV"<<
        " E:"<<fKineticEnergy<<" MeV"<<
        "  EnergyDeposit:"<<fEnergyDeposit<<" MeV "<<
        "  time:"<<fTime<<" ns "<<
        " x= "<<fPosition.X()<<" cm "<<
        " y= "<<fPosition.Y()<<" cm "<<
        " z= "<<fPosition.Z()<<" cm "<<
        " S= "<<fTrackStep<<" cm "<<
        " L= "<<fTrackLength<<" cm "<<
        " px= "<<fMomentum.Px()<<" GeV/c "<<
        " py= "<<fMomentum.Py()<<" GeV/c "<<
        " pz= "<<fMomentum.Pz()<<" GeV/c "<<std::endl;

   return true;
}
// -------------------------------------------------------------------------
bool R3BTPCHitSim::PrintTrackStatus()
{
   int s = fTrackStatus;
   int newTrack;
   int trackDisappeared;
   int trackStop;
   int trackAlive;
   int trackEntering;
   int trackExiting;
   int trackInside;
   int trackOut;

   newTrack = s/10000000;
   s -= newTrack*10000000;

   trackDisappeared = s/1000000;
   s -= trackDisappeared*1000000;

   trackStop = s/100000;
   s -= trackStop*100000;

   trackAlive = s/10000;
   s -= trackAlive*10000;

   trackEntering = s/1000;
   s -= trackEntering*1000;

   trackExiting = s/100;
   s -= trackExiting*100;

   trackInside = s/10;
   s -= trackInside*10;

   trackOut = s;

     std::cout<<"================"<<
        fParticleName.Data()<<" trackid="<<fTrackID<<
        " ParentTrackID="<<fParentTrackID<<
        "  at Vol:"<<fVolName<<std::endl;
   std::cout<<"=TrackTime: "<<fTime<<"ns"<<std::endl;
   std::cout<<"=IsNewTrack: "<<newTrack<<std::endl;
   std::cout<<"=IsTrackDisappeared: "<<trackDisappeared<<std::endl;
   std::cout<<"=IsTrackStop: "<<trackStop<<std::endl;
   std::cout<<"=IsTrackAlive: "<<trackAlive<<std::endl;
   std::cout<<"=IsTrackEntering: "<<trackEntering<<std::endl;
   std::cout<<"=IsTrackExiting: "<<trackExiting<<std::endl;
   std::cout<<"=IsTrackInside: "<<trackInside<<std::endl;
   std::cout<<"=IsTrackOut: "<<trackOut<<std::endl;
   std::cout<<"  EnergyDeposit:"<<fEnergyDeposit<<" MeV "<<
        "  time:"<<fTime<<" ns "<<
        " x= "<<fPosition.X()<<" cm "<<
        " y= "<<fPosition.Y()<<" cm "<<
        " z= "<<fPosition.Z()<<" cm "<<std::endl;

   return true;
}
