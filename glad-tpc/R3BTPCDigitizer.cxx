#include "R3BTPCDigitizer.h"
#include "TClonesArray.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"


// includes for modeling
#include "TGeoManager.h"
#include "TParticle.h"
#include "TVirtualMC.h"
#include "TGeoMatrix.h"
#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoCompositeShape.h"
#include "TGeoShapeAssembly.h"


#include "TVector3.h"
#include "TMath.h"
#include "TRandom.h"
#include "TH1F.h"
#include "TH2F.h"
#include <string>
#include <iostream>

#include "R3BTPCSetup.h"


#include "R3BTPCHitSim.h"
#include "R3BTPCDigi.h"
#include "R3BMCTrack.h"

#define U_MEV 931.4940954
#define pi 3.14159265359 
#define DEBUG 0
		
using std::cout;
using std::endl;
		

//___________________________________________________________
R3BTPCDigitizer::R3BTPCDigitizer() :
  FairTask("R3B TPC Digitization scheme ") 
{cout<<"R3BTPCDigitizer^v^ yeleisun"<<endl;}


//___________________________________________________________
R3BTPCDigitizer::~R3BTPCDigitizer() {}


//___________________________________________________________
void R3BTPCDigitizer::SetParContainers() {

  // Get run and runtime database
  FairRunAna* run = FairRunAna::Instance();
  if ( ! run ) Fatal("SetParContainers", "No analysis run");

}
//___________________________________________________________
InitStatus R3BTPCDigitizer::Init() {

  FairRootManager* ioman = FairRootManager::Instance();
  if ( ! ioman ) Fatal("Init", "No FairRootManager");
  //___by the name during register !!!
  fTPCHitSimCollection = (TClonesArray*) ioman->GetObject("TPCHitSimCollection");
   
  // Register output array TPCDigi
  fTPCDigiCollection = new TClonesArray("R3BTPCDigi",1000);
  ioman->Register("TPCDigi", "Digital response of TPC", fTPCDigiCollection, kTRUE);
  
  GetTPCParameters();
  eventNo=0;
  
  return kSUCCESS;
}

//_____________for each event________________________________
void R3BTPCDigitizer::Exec(Option_t* opt) {

   //____________________________________________
   Reset();
   adigi = new R3BTPCDigi();
   adigi->ClearEvent();
   trackNo = 0;
   tpctrackNo = 0;

   //____________________________________________
   adigi->eventid = eventNo;

   eventNo++;

   if (eventNo%100==0)
   {
      cout<<"\r events: "<<eventNo<<flush;
   }
     

   //____________________________________________
   Int_t nhits = fTPCHitSimCollection->GetEntries();
   std::map<int, int> fBufferMap;//hitid, trackid
   std::map<int, int> fTPCBufferMap;//hitid, trackid
   fBufferMap.clear();
   fTPCBufferMap.clear();

   std::map<int,int>::iterator it;

   if(nhits>0)
   for(int i=0;i<nhits;i++)
   {
   
        ResetTrackStatus();

        R3BTPCHitSim *ahit = (R3BTPCHitSim*) fTPCHitSimCollection->At(i);     
        GetTrackStatus(ahit->fTrackStatus, NewTrack, TrackDisappeared, TrackStop, 
              TrackAlive, TrackEntering, TrackExiting, TrackInside, TrackOut);

        //ahit->Print();
        if(DEBUG)
        ahit->PrintTrackStatus();

       //________________________________________________________________________
       int trackid = ahit->fTrackID;
       it = fBufferMap.find(trackid);
       if(it==fBufferMap.end()) //a new Track
       {
           trackNo++;
           fBufferMap.insert(std::pair<int,int>(trackid, i));
           //if(NewTrack>0)  //not work for primary particle
           RecordBeginOfTrack(ahit);
       }

       //________________________track counter in TPC
       if(ahit->fVolName=="TPC") 
       {
          trackid = ahit->fTrackID;
          it = fTPCBufferMap.find(trackid);
          if(it==fTPCBufferMap.end()) //a new Track in TPC
          {
              tpctrackNo = trackNo;
              fTPCBufferMap.insert(std::pair<int,int>(trackid, i));
          }
       }

       //________________________________________________________________________
       if(ahit->fVolName=="TPC")   RecordStepDEtpc(ahit);
       else if(ahit->fVolName=="Target")   RecordStepDEtarget(ahit);
       else if(ahit->fVolName=="Chamber")   RecordStepDEchamber(ahit);
       else if(ahit->fVolName=="InnerRohacell")   RecordStepDEInnerRohacell(ahit);
       else if(ahit->fVolName=="OuterRohacell")   RecordStepDEOuterRohacell(ahit);
       else if(ahit->fVolName=="Kapton")   RecordStepDEKapton(ahit);
       else if(ahit->fVolName=="WindowTube"||
             ahit->fVolName=="WindowEntrance"||
             ahit->fVolName=="WindowOutcoming")   RecordStepDEwindow(ahit);

       //________________________________________________________________________
       if(i<nhits-1)
       {
          R3BTPCHitSim *anhit = (R3BTPCHitSim*) fTPCHitSimCollection->At(i+1);     
          if(ahit->fTrackID!=anhit->fTrackID)//last hit of a track in the world
          RecordEndOfTrack(ahit);
       }
       else if(i=nhits-1)//last hit
       RecordEndOfTrack(ahit);

       //________________________________________________________________________
       //if(TrackDisappeared>0||TrackStop>0)  RecordEndOfTrack(ahit);
       //if(TrackDisappeared>0||TrackStop>0||TrackExiting)  RecordSEDOfTrack(ahit);//correct if there is only TPC in the setup !!
   }
   
   AddHit(*adigi);
}
//_______________________________________________________________
Bool_t R3BTPCDigitizer::AddHit(R3BTPCDigi& digi)
{
  TClonesArray& clref = *fTPCDigiCollection;
  Int_t size = clref.GetEntriesFast();
  new(clref[size]) R3BTPCDigi(digi);

  return true;

}
//___________________________________________________
void R3BTPCDigitizer::RecordStepDEtpc(const R3BTPCHitSim* ahit)
{

    double	edep = ahit->fEnergyDeposit*1e6;//in eV
    double   step_length = ahit->fTrackStep;//in cm

    if(edep>0.)
    {

       //________from lab change to TPC local frame
       TLorentzVector fPos = ahit->fPosition;

       fPos.RotateY(-1*TargetAngle*TMath::DegToRad());
       TVector3 voffset(TargetOffsetX, TargetOffsetY, TargetOffsetZ);//offset before ratation
       double x = fPos.X() - voffset.X();
       double y = fPos.Y() - voffset.Y();
       double z = fPos.Z() - voffset.Z();

       //________________local position in TPC !!!
       adigi->x_tpc.push_back(x);
       adigi->y_tpc.push_back(y);
       adigi->z_tpc.push_back(z);
       adigi->e_tpc.push_back(edep);
       adigi->s_tpc.push_back(step_length);
       adigi->Et_tpc_tot +=edep;
       adigi->s_tpc_tot +=step_length;

       //adigi->tpctrackid.push_back(tpctrackNo-1);//start from zero
       adigi->trackid_tpc.push_back(tpctrackNo-1);

       Et_tpc += edep;
    }
   //else std::cout << "Recording data step by step in the TPC: energy too low..." << std::endl; 
   if(DEBUG)
   cout<<"---------RecordStepDEtpc, Et_tpc:"<<Et_tpc<<"eV"<<endl;
}
//___________________________________________________________
void R3BTPCDigitizer::RecordStepDEchamber(const R3BTPCHitSim* ahit)
{

   double	edep = ahit->fEnergyDeposit;//in MeV
   if(edep>0.){Et_ch += edep;}

}
//___________________________________________________________
void R3BTPCDigitizer::RecordStepDEtarget(const R3BTPCHitSim* ahit)
{
   
   double	edep = ahit->fEnergyDeposit;//in MeV
   if(edep>0.){

      double x = ahit->fPosition.X();
      double y = ahit->fPosition.Y();
      double z = ahit->fPosition.Z();
      
      adigi->x_tar.push_back(x);
      adigi->y_tar.push_back(y);
      adigi->z_tar.push_back(z);
      adigi->e_tar.push_back(edep);

      Et_tar += edep;

   }

   if(DEBUG)
   cout<<"---------RecordStepDEtarget, Et_tar:"<<Et_tar<<"MeV"<<endl;
}
//___________________________________________________________
void R3BTPCDigitizer::RecordStepDEwindow(const R3BTPCHitSim* ahit)
{

   double	edep = ahit->fEnergyDeposit;//in MeV
   if(edep>0.){Et_win += edep;}

}
//___________________________________________________________
void R3BTPCDigitizer::RecordStepDEInnerRohacell(const R3BTPCHitSim* ahit)
{
   double	edep = ahit->fEnergyDeposit;//in MeV
   if(edep>0.){Et_InnerRohacell += edep;}
}
//___________________________________________________________
void R3BTPCDigitizer::RecordStepDEOuterRohacell(const R3BTPCHitSim* ahit)
{
   double	edep = ahit->fEnergyDeposit;//in MeV
   if(edep>0.){Et_OuterRohacell += edep;}
}
//___________________________________________________________
void R3BTPCDigitizer::RecordStepDEKapton(const R3BTPCHitSim* ahit)
{
   double	edep = ahit->fEnergyDeposit;//in MeV
   if(edep>0.){Et_Kapton += edep;}
}
//_______________________________________________________________________
void R3BTPCDigitizer::RecordBeginOfTrack(const R3BTPCHitSim* ahit)
{
    //______________________
    TLorentzVector fPos = ahit->fPosition;

    cout<<"BeginOfTrack1:"<<fPos.X()<<"cm "<<fPos.Y()<<"cm "<<fPos.Z()<<"cm "<<endl;

    fPos.RotateY(-1*TargetAngle*TMath::DegToRad());
    TVector3 voffset(TargetOffsetX, TargetOffsetY, TargetOffsetZ);//offset before ratation
    double x = fPos.X() - voffset.X();
    double y = fPos.Y() - voffset.Y();
    double z = fPos.Z() - voffset.Z();

    cout<<"BeginOfTrack2:"<<x<<"cm "<<y<<"cm "<<z<<"cm "<<endl;

    //double x = ahit->fPosition.X();
    //double y = ahit->fPosition.Y();
    //double z = ahit->fPosition.Z();

  	int charge = (int) (ahit->fCharge);
    int pdg = ahit->fPDGCode;
  	double mass = ahit->fMass*1000; //Gev->MeV
  	int atomN = (int)(mass/U_MEV); //Gev->MeV

    TLorentzVector fMomentum = ahit->fMomentum;
    fMomentum.RotateY(-1*TargetAngle*TMath::DegToRad());

    double px = fMomentum.Px();
    double py = fMomentum.Py();
    double pz = fMomentum.Pz();
    double energy = fMomentum.E();
    double t = ahit->fTime;
    
    px = px*1000;//GeV/-->MeV/c
    py = py*1000;//GeV/-->MeV/c
    pz = pz*1000;//GeV/-->MeV/c
    energy = energy*1000;//GeV-->MeV

    TVector3 Momentum(px, py, pz);      	

    double theta = Momentum.Theta();
    double phi= Momentum.Phi();

    //______________________________
    adigi->pdg0.push_back(pdg);
    adigi->Z.push_back(charge);
    adigi->A.push_back(atomN);

    adigi->theta0.push_back(theta);
    adigi->phi0.push_back(phi);
    adigi->energy0.push_back(energy);
    adigi->momentum0.push_back(Momentum.Mag());

    adigi->x0.push_back(x);
    adigi->y0.push_back(y);
    adigi->z0.push_back(z);
    adigi->t0.push_back(t);
    //adigi->trackid.push_back(ahit->fTrackID);//trackid of geant4
    if(trackNo>=1)
    adigi->trackid.push_back(trackNo-1);//start from zero
    if(tpctrackNo>=1)
    adigi->tpctrackid.push_back(tpctrackNo-1);//start from zero

    //______________________________
	Et_tar=0.;
	Et_win=0.;
	Et_tpc=0.;
	Et_ch=0.;
	Et_InnerRohacell=0.;
	Et_OuterRohacell=0.;
	Et_Kapton=0.;

    if(DEBUG)
    cout<<"---------RecordBeginOfTrack, Et_tar:"<<Et_tar<<"MeV, Et_tpc:"
       <<Et_tpc<<"eV"<<endl;
}
//_______________________________________________________________________
void R3BTPCDigitizer::RecordEndOfTrack(const R3BTPCHitSim* ahit)
{
    //______________________
    TLorentzVector fPos = ahit->fPosition;

    fPos.RotateY(-1*TargetAngle*TMath::DegToRad());
    TVector3 voffset(TargetOffsetX, TargetOffsetY, TargetOffsetZ);//offset before ratation
    double x = fPos.X() - voffset.X();
    double y = fPos.Y() - voffset.Y();
    double z = fPos.Z() - voffset.Z();

    //_______
    //double x = ahit->fPosition.X();
    //double y = ahit->fPosition.Y();
    //double z = ahit->fPosition.Z();

  	int charge = (int) (ahit->fCharge);
    int pdg = ahit->fPDGCode;
  	double mass = ahit->fMass*1000; //Gev->MeV
  	int atomN = (int)(mass/U_MEV); //Gev->MeV

    TLorentzVector fMomentum = ahit->fMomentum;
    fMomentum.RotateY(-1*TargetAngle*TMath::DegToRad());

    double px = fMomentum.Px();
    double py = fMomentum.Py();
    double pz = fMomentum.Pz();
    double energy = fMomentum.E();
    double t = ahit->fTime;
    
    px = px*1000;//GeV/-->MeV/c
    py = py*1000;//GeV/-->MeV/c
    pz = pz*1000;//GeV/-->MeV/c
    energy = energy*1000;//GeV-->MeV

    TVector3 Momentum(px, py, pz);      	

    double theta = Momentum.Theta();
    double phi= Momentum.Phi();

    //______________________________
    adigi->pdg1.push_back(pdg);
    adigi->Z1.push_back(charge);
    adigi->A1.push_back(atomN);

    adigi->theta1.push_back(theta);
    adigi->phi1.push_back(phi);
    adigi->energy1.push_back(energy);
    adigi->momentum1.push_back(Momentum.Mag());

    adigi->x1.push_back(x);
    adigi->y1.push_back(y);
    adigi->z1.push_back(z);
    adigi->t1.push_back(t);

    //__________________________________
    adigi->Et_tar.push_back(Et_tar);
    adigi->Et_ch.push_back(Et_ch);
    adigi->Et_win.push_back(Et_win);
    adigi->Et_tpc.push_back(Et_tpc);
    adigi->Et_Kapton.push_back(Et_Kapton);
    adigi->Et_InnerRohacell.push_back(Et_InnerRohacell);
    adigi->Et_OuterRohacell.push_back(Et_OuterRohacell);

    if(DEBUG)
    cout<<"---------RecordEndOfTrack, Et_tar:"<<Et_tar<<"MeV, Et_tpc:"
       <<Et_tpc<<"eV"<<endl;
}
//_______________________________________________________________________
void R3BTPCDigitizer::RecordSEDOfTrack(const R3BTPCHitSim* ahit)
{
   ;
}
//_______________________________________________________________________
void R3BTPCDigitizer::Reset(){
 if (fTPCDigiCollection ) fTPCDigiCollection->Clear();

}   

//_______________________________________________________________________
bool R3BTPCDigitizer::GetTrackStatus(int s,
    int& newTrack,
    int& trackDisappeared,
    int& trackStop,
    int& trackAlive,
    int& trackEntering,
    int& trackExiting,
    int& trackInside,
    int& trackOut)
{

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

   return true;
}
//__________________________________________________________________
void R3BTPCDigitizer::GetTPCParameters()
{

  R3BTPCSetup* Setup = new R3BTPCSetup(1);

  TargetLength           = Setup->TargetLength/2.;//cm
  TargetRadius           = Setup->TargetRadius;
  WindowThickness        = Setup->WindowThickness/2.;
  ChamberLength          = Setup->ChamberLength/2.;
  ChamberInnerRadius     = Setup->ChamberInnerRadius; 
  TPCRadiusExt           = Setup->TPCRadiusExt; 
  TPCLx                  = Setup->TPCLx/2.; 
  TPCLy                  = Setup->TPCLy/2.; 
  TPCLz                  = Setup->TPCLz/2.; 
  ChamberThickness       = Setup->ChamberThickness;
  InnerRohacellThickness = Setup->InnerRohacellThickness;
  OuterRohacellThickness = Setup->OuterRohacellThickness;
  KaptonThickness        = Setup->KaptonThickness;
  TargetAngle            = Setup->TargetAngle;//deg
  TargetOffsetX          = Setup->TargetOffsetX;//cm
  TargetOffsetY          = Setup->TargetOffsetY;//cm
  TargetOffsetZ          = Setup->TargetOffsetZ;//cm

   if(Setup)
      delete Setup;
}
//__________________________________________________________________
void R3BTPCDigitizer::Finish()
{
// Write control histograms
//   TOFelosshis->Write();

}

ClassImp(R3BTPCDigitizer)
