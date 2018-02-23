#ifndef R3BTPCDIGITIZER_H
#define R3BTPCDIGITISER_H 1


#include "FairTask.h"
#include <map>
#include <string>

class R3BTPCHitSim;
class R3BTPCDigi;
class TClonesArray;
class TObjectArray;
class TH1F;
class TH2F;


class R3BTPCDigitizer : public FairTask
{

 public:

  /** Default constructor **/  
  R3BTPCDigitizer();


  /** Destructor **/
  ~R3BTPCDigitizer();


  /** Virtual method Init **/
  virtual InitStatus Init();


  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  virtual void Finish();
  virtual void Reset();


  Bool_t AddHit(R3BTPCDigi& adigi);

  protected: 
  TClonesArray* fTPCDigiCollection;

  TClonesArray* fTPCHitSimCollection;


  //- Control Hitograms
  TH1F *TOFelosshis;
  
  int eventNo;
  int trackNo;
  int tpctrackNo;
  //________________________TPC parameters
  Double_t TargetLength;
  Double_t TargetRadius;
  Double_t WindowThickness;
  Double_t ChamberLength;
  Double_t ChamberInnerRadius;
  Double_t TPCRadiusExt;
  Double_t TPCLx;
  Double_t TPCLy;
  Double_t TPCLz;
  Double_t ChamberThickness;
  Double_t InnerRohacellThickness;
  Double_t OuterRohacellThickness;
  Double_t KaptonThickness;
  Double_t TargetAngle;
  Double_t TargetOffsetX;
  Double_t TargetOffsetY;
  Double_t TargetOffsetZ;
  int BeamZ, BeamA;
  
  //________________________________________
  inline void ResetTrackStatus(){
  NewTrack = -1;
  TrackDisappeared = -1;
  TrackStop = -1;
  TrackAlive = -1;
  TrackEntering = -1;
  TrackExiting =-1;
  TrackInside = -1;
  TrackOut = -1;};
  
  //________________________________________
  private:
  int NewTrack;
  int TrackDisappeared;
  int TrackStop;
  int TrackAlive;
  int TrackEntering;
  int TrackExiting;
  int TrackInside;
  int TrackOut;

  //________________________________________
  virtual void SetParContainers();
  void GetTPCParameters();

  //________________________________________
  bool GetTrackStatus(int s,
    int& NewTrack,
    int& TrackDisappeared,
    int& TrackStop,
    int& TrackAlive,
    int& TrackEntering,
    int& TrackExiting,
    int& TrackInside,
    int& TrackOut);

  R3BTPCDigi* adigi;

  public:

   double Et_tar, Et_win, Et_ch, Et_InnerRohacell, Et_OuterRohacell, Et_Kapton, Et_tpc;

  //________________________________________
  public:
  void RecordBeginOfRun(){};
  void RecordEndOfRun(){};

  void RecordBeginOfEvent(){};
  void RecordEndOfEvent(){};

  void RecordBeginOfTrack(const R3BTPCHitSim*);//
  void RecordEndOfTrack(const R3BTPCHitSim *);//
  void RecordSEDOfTrack(const R3BTPCHitSim *);//stop/exiting/disappeared

  void RecordStepDEtarget(const R3BTPCHitSim *);
  void RecordStepDEchamber(const R3BTPCHitSim *);
  void RecordStepDEtpc(const R3BTPCHitSim*);//
  void RecordStepDEwindow(const R3BTPCHitSim*);
  void RecordStepDEInnerRohacell(const R3BTPCHitSim*);
  void RecordStepDEOuterRohacell(const R3BTPCHitSim*);
  void RecordStepDEKapton(const R3BTPCHitSim*);
  void WriteDEDXTable(int, int){};

  ClassDef(R3BTPCDigitizer,12);
  
};

#endif
