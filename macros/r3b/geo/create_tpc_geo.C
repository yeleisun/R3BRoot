#include <iomanip>
#include <iostream>
#include "TGeoManager.h"
#include "TMath.h"
#include "TFile.h"

TGeoRotation *zeroRot = new TGeoRotation;
TGeoTranslation *zeroTrans = new TGeoTranslation;
TGeoCombiTrans *zeroRotTrans = new TGeoCombiTrans(*zeroTrans, *zeroRot);


// Create a null translation
TGeoTranslation *fGlobalTrans = new TGeoTranslation();
// Create Matrix Unity
TGeoRotation *fGlobalRot = new TGeoRotation();
TGeoRotation *fRefRot = NULL;

TGeoManager*  gGeoMan = NULL;

Double_t fThetaX = 0.;
Double_t fThetaY = 0.;
Double_t fThetaZ = 0.;
Double_t fPhi   = 0.;
Double_t fTheta = 0.;
Double_t fPsi   = 0.;
Double_t fX = 0.;
Double_t fY = 0.;
Double_t fZ = 0.;
Bool_t fLocalTrans = kFALSE;
Bool_t fLabTrans = kTRUE;

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

Double_t WorldSizeX;
Double_t WorldSizeY;
Double_t WorldSizeZ;

void ConstructTPC(TGeoVolume* pWorld);

string GEOTAG;

void create_tpc_geo(const char* geoTag="v1")
{
   GEOTAG = std::string(geoTag);
   TString path = getenv("TPCLIBDIR");
   TString install_dir = ".include"+path;
   gROOT->ProcessLine(install_dir.Data());
  // Path = ".L"+path+"/libR3BTPCSetup.so";
  // gROOT->ProcessLine(Path.Data());


  // -------   Load media from media file   -----------------------------------
  FairGeoLoader*    geoLoad = new FairGeoLoader("TGeo","FairGeoLoader");
  FairGeoInterface* geoFace = geoLoad->getGeoInterface();
  TString geoPath = gSystem->Getenv("VMCWORKDIR");
  TString medFile = geoPath + "/geometry/media_tpc.geo";
  geoFace->setMediaFile(medFile);
  geoFace->readMedia();
  gGeoMan = gGeoManager;
  // --------------------------------------------------------------------------



  // -------   Geometry file name (output)   ----------------------------------
  TString geoFileName = geoPath + "/geometry/tpc_";
  geoFileName = geoFileName + geoTag + ".geo.root";
  // --------------------------------------------------------------------------



  // -----------------   Get and create the required media    -----------------
  FairGeoMedia*   geoMedia = geoFace->getMedia();
  FairGeoBuilder* geoBuild = geoLoad->getGeoBuilder();

  //geoMedia->print();
  //
  FairGeoMedium* mvacuum      = geoMedia->getMedium("vacuum");
  if ( ! mvacuum ) Fatal("Main", "FairMedium vacuum not found");
  geoBuild->createMedium(mvacuum);
  TGeoMedium* pvacuum = gGeoMan->GetMedium("vacuum");
  if ( ! pvacuum ) Fatal("Main", "Medium vacuum not found");

  FairGeoMedium* mair      = geoMedia->getMedium("air");
  if ( ! mair ) Fatal("Main", "FairMedium air not found");
  geoBuild->createMedium(mair);
  TGeoMedium* pair = gGeoMan->GetMedium("air");
  if ( ! pair ) Fatal("Main", "Medium Air not found");
  
  FairGeoMedium* mTof      = geoMedia->getMedium("LH2");
  if ( ! mTof ) Fatal("Main", "FairMedium LH2 not found");
  geoBuild->createMedium(mTof);
  TGeoMedium* pMed34 = gGeoMan->GetMedium("LH2");
  if ( ! pMed34 ) Fatal("Main", "Medium LH2 not found");

  FairGeoMedium* mTof      = geoMedia->getMedium("carbon");
  if ( ! mTof ) Fatal("Main", "FairMedium carbon not found");
  geoBuild->createMedium(mTof);
  TGeoMedium* pMed34 = gGeoMan->GetMedium("carbon");
  if ( ! pMed34 ) Fatal("Main", "Medium carbon not found");

  FairGeoMedium* mAl      = geoMedia->getMedium("mylar");
  if ( ! mAl ) Fatal("Main", "FairMedium mylar not found");
  geoBuild->createMedium(mAl);
  TGeoMedium* pAl = gGeoMan->GetMedium("mylar");
  if ( ! pAl ) Fatal("Main", "Medium mylar not found");

  FairGeoMedium* minox      = geoMedia->getMedium("inox");
  if ( ! minox ) Fatal("Main", "FairMedium inox not found");
  geoBuild->createMedium(minox);
  TGeoMedium* pinox = gGeoMan->GetMedium("inox");
  if ( ! pinox ) Fatal("Main", "Medium inox not found");

  FairGeoMedium* mrohacell      = geoMedia->getMedium("rohacell");
  if ( ! mrohacell ) Fatal("Main", "FairMedium rohacell not found");
  geoBuild->createMedium(mrohacell);
  TGeoMedium* prohacell = gGeoMan->GetMedium("rohacell");
  if ( ! prohacell ) Fatal("Main", "Medium rohacell not found");

  FairGeoMedium* mkapton      = geoMedia->getMedium("kapton");
  if ( ! mkapton ) Fatal("Main", "FairMedium kapton not found");
  geoBuild->createMedium(mkapton);
  TGeoMedium* pkapton = gGeoMan->GetMedium("kapton");
  if ( ! pkapton ) Fatal("Main", "Medium kapton not found");

  FairGeoMedium* mmix      = geoMedia->getMedium("mix");
  if ( ! mmix ) Fatal("Main", "FairMedium mix not found");
  geoBuild->createMedium(mmix);
  TGeoMedium* pmix = gGeoMan->GetMedium("mix");
  if ( ! pmix ) Fatal("Main", "Medium mix not found");
  //_________________________________

  // --------------   Create geometry and top volume  -------------------------
  gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
  gGeoMan->SetName("tpcgeom");
  TGeoVolume* top = new TGeoVolumeAssembly("TOP");
  gGeoMan->SetTopVolume(top);
  top->SetVisLeaves(kTRUE);
  gGeoManager->SetVisLevel(4);
  gGeoManager->SetVisOption(0);
  // --------------------------------------------------------------------------

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
 //

  WorldSizeX            = 1.2*2*TPCLx;
  WorldSizeY            = 1.2*2*TPCLy;
  WorldSizeZ            = 1.2*2*TPCLz;

  // Geometry description
  //TGeoVolume *pAWorld =  gGeoManager->GetTopVolume();
  
  // TPC main area
  TGeoShape *tpc_box = new TGeoBBox("TPC_Box",
				     WorldSizeX,
				     WorldSizeY,
				     WorldSizeZ);
  TGeoVolume* pWorld = new TGeoVolume("TPC_box",tpc_box, pvacuum);

  //__________________________
  ConstructTPC(pWorld);

  //_____________________________Globle definition of TPC position in cm
  fGlobalRot->RotateY(TargetAngle);//deg
  TVector3 gTrans(TargetOffsetX, TargetOffsetY, TargetOffsetZ);//offset before ratation
  gTrans.RotateY(TargetAngle*TMath::DegToRad());

  fGlobalTrans->SetTranslation(gTrans.X(),gTrans.Y(),gTrans.Z());

  TGeoCombiTrans *pGlobal = new TGeoCombiTrans(*fGlobalTrans,*fGlobalRot);
  //pAWorld->AddNode(pWorld, 0, pGlobal);
  top->AddNode(pWorld, 0, pGlobal);

  //____________________________________
  gGeoMan->CloseGeometry();
  gGeoMan->CheckOverlaps(0.001);
  gGeoMan->PrintOverlaps();
  gGeoMan->Test();

  cout<<"vis option "<<gGeoMan->GetVisOption()<<" =====  vis level "<<gGeoMan->GetVisLevel()<<endl;


  TFile* geoFile = new TFile(geoFileName, "RECREATE");
  top->Draw("ogl");
  top->Write();
  geoFile->Close();
}
//________________________________________________________________
void ConstructTPC(TGeoVolume* pWorld)
{

   TGeoMedium *TargetMaterial = gGeoManager->GetMedium("LH2");
   TGeoMedium *ChamberMaterial = gGeoManager->GetMedium("inox");
   TGeoMedium *TPCMaterial = gGeoManager->GetMedium("mix");
   TGeoMedium *GapMaterial = gGeoManager->GetMedium("air");
   TGeoMedium *WindowMaterial = gGeoManager->GetMedium("mylar");
   TGeoMedium *KaptonMaterial = gGeoManager->GetMedium("kapton");
   TGeoMedium *InnerRohacellMaterial = gGeoManager->GetMedium("rohacell");
   TGeoMedium *OuterRohacellMaterial = gGeoManager->GetMedium("rohacell");
 
  //                               
  TGeoShape* solidTarget=0;  TGeoVolume* logicTarget=0;
  TGeoShape* solidChamber=0; TGeoVolume* logicChamber=0;
  TGeoShape* solidTPC=0;     TGeoVolume* logicTPC=0;
  TGeoShape* solidGap=0;     TGeoVolume* logicGap=0;

  //___________Target
  if(GEOTAG=="v1")
  {
     solidTarget = new TGeoTubeSeg("Target", 0.,TargetRadius,TargetLength,0,360.);
     logicTarget = new TGeoVolume("Target",solidTarget,TargetMaterial);
  }
  else if(GEOTAG=="v2")
  {
     TargetLength = 4.0/2;
     WindowThickness = 0.0001;//no window
     TargetMaterial = gGeoManager->GetMedium("carbon");
     solidTarget = new TGeoTubeSeg("Target", 0.,TargetRadius,TargetLength, 0,360.);
     logicTarget = new TGeoVolume("Target",solidTarget,TargetMaterial);
  }

  pWorld->AddNode(logicTarget, 0, new TGeoCombiTrans(0.,0.,TargetLength,zeroRot));

  //___________Chamber
  //solidChamber = new TGeoTubeSeg  ("Chamber",ChamberInnerRadius,ChamberInnerRadius+ChamberThickness,ChamberLength,0,360.);
  TGeoShape* chamber_box1 = new TGeoBBox("chamber_box1",
					 ChamberInnerRadius, 
					 ChamberInnerRadius, 
					 ChamberLength);
  TGeoShape* chamber_box2 = new TGeoBBox("chamber_box2",
					 ChamberInnerRadius+ChamberThickness, 
					 ChamberInnerRadius+ChamberThickness, 
					 ChamberLength);

  TGeoTranslation *tc = new TGeoTranslation("tc",0,0,-1*ChamberThickness);
  tc->RegisterYourself();
  solidChamber = new TGeoCompositeShape("Chamber", "chamber_box2 - chamber_box1:tc");

  logicChamber = new TGeoVolume("Chamber",solidChamber,ChamberMaterial);
  pWorld->AddNode(logicChamber, 0, new TGeoCombiTrans(0.,0.,ChamberLength,zeroRot));
  
  //_______________________ Inner Rohacell
  //solidInnerRohacell = new TGeoTubeSeg("InnerRohacell", 
  //                     ChamberInnerRadius + ChamberThickness,
  //                     ChamberInnerRadius + ChamberThickness+InnerRohacellThickness,
  //                     ChamberLength,0,360.);

  TGeoShape* innerRohacell_box1 = new TGeoBBox("innerRohacell_box1",
					 ChamberInnerRadius+ChamberThickness, 
					 ChamberInnerRadius+ChamberThickness, 
					 ChamberLength+InnerRohacellThickness*0.5);//================================================
  TGeoShape* innerRohacell_box2 = new TGeoBBox("innerRohacell_box2",
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness, 
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness, 
					 ChamberLength+InnerRohacellThickness*0.5);
  TGeoTranslation *ti = new TGeoTranslation("ti",0,0,-1*InnerRohacellThickness);
  ti->RegisterYourself();
  
  solidInnerRohacell = new TGeoCompositeShape("InnerRohacell", "innerRohacell_box2 - innerRohacell_box1:ti");

  logicInnerRohacell = new TGeoVolume("InnerRohacell",solidInnerRohacell, InnerRohacellMaterial);
  pWorld->AddNode(logicInnerRohacell, 0, new TGeoCombiTrans(0.,0.,ChamberLength+InnerRohacellThickness*0.5,zeroRot));

  //_________Outer Rohacell
  //solidOuterRohacell = new TGeoTubeSeg("OuterRohacell",
  //                     ChamberInnerRadius + ChamberThickness + InnerRohacellThickness + KaptonThickness,
  //                     ChamberInnerRadius + ChamberThickness + InnerRohacellThickness + KaptonThickness+OuterRohacellThickness,
  //                     ChamberLength,0,360.); 
  
  TGeoShape* outerRohacell_box1 = new TGeoBBox("outerRohacell_box1",
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness, 
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness, 
					 ChamberLength+InnerRohacellThickness*0.5+KaptonThickness*0.5+OuterRohacellThickness*0.5);
  TGeoShape* outerRohacell_box2 = new TGeoBBox("outerRohacell_box2",
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness+OuterRohacellThickness, 
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness+OuterRohacellThickness, 
					 ChamberLength+InnerRohacellThickness*0.5+KaptonThickness*0.5+OuterRohacellThickness*0.5);
  TGeoTranslation *to = new TGeoTranslation("to",0,0,-1*OuterRohacellThickness);
  to->RegisterYourself();
  solidOuterRohacell = new TGeoCompositeShape("OuterRohacell", "outerRohacell_box2 - outerRohacell_box1:to");
                       
  logicOuterRohacell = new TGeoVolume("OuterRohacell",solidOuterRohacell,OuterRohacellMaterial);
  pWorld->AddNode(logicOuterRohacell, 0, new TGeoCombiTrans(0.,0.,ChamberLength+InnerRohacellThickness*0.5+KaptonThickness*0.5+OuterRohacellThickness*0.5,zeroRot));

  //_________________Kapton
  //solidKapton = new TGeoTubeSeg("Kapton",
  //              ChamberInnerRadius + ChamberThickness+InnerRohacellThickness,
  //              ChamberInnerRadius + ChamberThickness+InnerRohacellThickness+KaptonThickness,
  //              ChamberLength,0,360.);
  //
  TGeoShape* kapton_box1 = new TGeoBBox("kapton_box1",
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness, 
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness, 
					 ChamberLength+InnerRohacellThickness*0.5+KaptonThickness*0.5);
  TGeoShape* kapton_box2 = new TGeoBBox("kapton_box2",
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness, 
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness, 
					 ChamberLength+InnerRohacellThickness*0.5+KaptonThickness*0.5);
  TGeoTranslation *tk = new TGeoTranslation("tk",0,0,-1*KaptonThickness);
  tk->RegisterYourself();
  solidKapton = new TGeoCompositeShape("Kapton", "kapton_box2 - kapton_box1:tk");


  logicKapton = new TGeoVolume("Kapton",solidKapton,KaptonMaterial);
  pWorld->AddNode(logicKapton, 0, new TGeoCombiTrans(0.,0.,ChamberLength+InnerRohacellThickness*0.5+KaptonThickness*0.5,zeroRot));

  //________________TPC
  //solidTPC = new TGeoTubeSeg("TPC",
  //           ChamberInnerRadius + ChamberThickness + InnerRohacellThickness + KaptonThickness + OuterRohacellThickness,
  //           TPCRadiusExt,
  //           ChamberLength,0,360.); 
  //
  TGeoShape* tpc_box1 = new TGeoBBox("tpc_box1",
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness+OuterRohacellThickness, 
					 ChamberInnerRadius+ChamberThickness+InnerRohacellThickness+KaptonThickness+OuterRohacellThickness, 
					 ChamberLength+ChamberThickness*0.5+InnerRohacellThickness*0.5+KaptonThickness*0.5+OuterRohacellThickness*0.5+0.1);
  cout<<"TPCLz ChamberLength "<<TPCLz<<"  "<<ChamberLength<<endl;
  TGeoTranslation *t1 = new TGeoTranslation("t1",0,0,-1*(TPCLz-(ChamberLength+ChamberThickness*0.5+InnerRohacellThickness*0.5+KaptonThickness*0.5+OuterRohacellThickness*0.5+0.1))-0.1);
  t1->RegisterYourself();
  TGeoShape* tpc_box2 = new TGeoBBox("tpc_box2",TPCLx, TPCLy,  TPCLz);
  solidTPC = new TGeoCompositeShape("TPC", "tpc_box2 - tpc_box1:t1");

  logicTPC = new TGeoVolume("TPC",solidTPC,TPCMaterial);
  pWorld->AddNode(logicTPC, 0, new TGeoCombiTrans(0.,0.,TPCLz,zeroRot));

  //______________window
  solidWindow0 = new TGeoTubeSeg("WindowTube",TargetRadius,TargetRadius+WindowThickness*2.,TargetLength,0,360.); 
  logicWindow0 = new TGeoVolume("WindowTube",solidWindow0,WindowMaterial);
  pWorld->AddNode(logicWindow0, 0, new TGeoCombiTrans(0.,0.,TargetLength,zeroRot));

  solidWindow1 = new TGeoTubeSeg("WindowEntrance", 0.,TargetRadius+2.*WindowThickness,WindowThickness,0,360.); 
  logicWindow1 = new TGeoVolume("WindowEntrance",solidWindow1,WindowMaterial);
  pWorld->AddNode(logicWindow1, 0, new TGeoCombiTrans(0.,0.,-1*WindowThickness,zeroRot));
  
  solidWindow2 = new TGeoTubeSeg("WindowOutcoming",0.,TargetRadius+2.*WindowThickness,WindowThickness,0,360.); 
  logicWindow2 = new TGeoVolume("WindowOutcoming",solidWindow2,WindowMaterial);
  pWorld->AddNode(logicWindow2, 0, new TGeoCombiTrans(0.,0.,2*TargetLength+WindowThickness,zeroRot));

  //__________________gap
  TGeoShape* gap_box1 = new TGeoTubeSeg("gap_box1", 0, TargetRadius+WindowThickness*2, TargetLength+2*WindowThickness, 0, 360.);
  TGeoTranslation *tg = new TGeoTranslation("tg",0,0,-1*(ChamberLength-0.5*ChamberThickness-(TargetLength+2*WindowThickness))-2*WindowThickness);
  tg->RegisterYourself();
  TGeoShape* gap_box2 = new TGeoBBox("gap_box2",ChamberInnerRadius, ChamberInnerRadius, ChamberLength-0.5*ChamberThickness);
  solidGap = new TGeoCompositeShape("gap", "gap_box2 - gap_box1:tg");

  logicGap = new TGeoVolume("Gap",solidGap,GapMaterial);
  pWorld->AddNode(logicGap, 0, new TGeoCombiTrans(0.,0.,ChamberLength-0.5*ChamberThickness,zeroRot));

  logicTarget->SetLineColor(kAzure);
  logicInnerRohacell->SetLineColor(kOrange);
  logicOuterRohacell->SetLineColor(kOrange);
  logicKapton->SetLineColor(kAzure);
  logicChamber->SetLineColor(kSpring);
  logicTPC->SetLineColor(kSpring);
  logicGap->SetLineColor(kWhite);
 
}
