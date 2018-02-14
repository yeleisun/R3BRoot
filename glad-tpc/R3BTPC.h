#ifndef R3BTPC_H
#define R3BTPC_H

#include <map>

#include "R3BDetector.h"
#include "TF1.h"
#include "TLorentzVector.h"
#include "TGraph.h"


class TClonesArray;
class R3BTPCHitSim;
class FairVolume;
class TGeoRotation;

class R3BTPC : public R3BDetector
{

 public:

  /** Default constructor **/
  R3BTPC();


  bool Record_flag;

  /** Standard constructor.
   *@param name    detetcor name
   *@param active  sensitivity flag
   **/
  R3BTPC(const char* name, Bool_t active);

    /** Standard constructor.
     *@param geoFile name of the ROOT geometry file
     *@param trans   position
     *@param rot     rotation
     */
    R3BTPC(const TString& geoFile, const TGeoTranslation& trans, const TGeoRotation& rot = TGeoRotation());

    /** Standard constructor.
     *@param geoFile name of the ROOT geometry file
     *@param combi   position + rotation
     */
    R3BTPC(const TString& geoFile, const TGeoCombiTrans& combi = TGeoCombiTrans());



  /** Destructor **/
  virtual ~R3BTPC();


  /** Virtual method ProcessHits
   **
   ** Defines the action to be taken when a step is inside the
   ** active volume. Creates a R3BTPCHitSim and adds it to the
   ** collection.
   *@param vol  Pointer to the active volume
   **/
  virtual Bool_t ProcessHits(FairVolume* vol = 0);


  /** Virtual method BeginEvent
   **
   ** If verbosity level is set, print hit collection at the
   ** end of the event and resets it afterwards.
   **/
  virtual void BeginEvent();

	
  /** Virtual method EndOfEvent
   **
   ** Added support for R3BRawHit
   ** If verbosity level is set, print hit collection at the
   ** end of the event and resets it afterwards.
   **/
  virtual void EndOfEvent();


  /** Virtual method Register
   **
   ** Registers the hit collection in the ROOT manager.
   **/
  virtual void Register();


  /** Accessor to the hit collection **/
  virtual TClonesArray* GetCollection(Int_t iColl) const;


  /** Virtual method Print
   **
   ** Screen output of hit collection.
   **/
  virtual void Print(Option_t* option="") const;


  /** Virtual method Reset
   **
   ** Clears the hit collection
   **/
  virtual void Reset();


   //virtual void   CopyClones( TClonesArray*,  TClonesArray*, Int_t);
   //virtual void   FinishPrimary();
   virtual void   FinishRun();
   //virtual void   BeginPrimary();
   virtual void   PostTrack();
   virtual void   PreTrack();
   //virtual void   FinishEvent();


  /** Virtual method Construct geometry
   **
   ** Constructs the STS geometry
   **/
  virtual void ConstructGeometry();
	

  virtual Bool_t CheckIfSensitive(std::string name);
  
  virtual void Initialize();


  virtual void SetSpecialPhysicsCuts();

Int_t GetTrackStatus(bool NewTrack,
    bool TrackDisappeared,
    bool TrackStop,
    bool TrackAlive,
    bool TrackEntering,
    bool TrackExiting,
    bool TrackInside,
    bool TrackOut);


//  void SaveGeoParams();

  private:

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


   //_______________________________
    TClonesArray*  fTPCHitSimCollection;

    Bool_t AddHit(R3BTPCHitSim& ahit);

    void GetTPCParameters();
	
    ClassDef(R3BTPC, 5);
};

#endif 
