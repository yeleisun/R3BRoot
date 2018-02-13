#ifndef R3BTPCSetup_h
#define R3BTPCSetup_h 1

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "TObject.h"
#include "TRandom.h"
#include "TMath.h"
#include <vector>


using namespace std;

class R3BTPCSetup:public TObject
{
public:

//initial conditions
double TargetRadius, TargetLength, ChamberInnerRadius, ChamberThickness;
double ChamberLength, InnerRohacellThickness, KaptonThickness, OuterRohacellThickness;
double TPCRadiusExt, WindowThickness;
double TPCLx,TPCLy, TPCLz;
double TargetAngle, TargetOffsetX, TargetOffsetY, TargetOffsetZ;
double GladAngle, GladOffsetX, GladOffsetY, GladOffsetZ;
double FieldAngle, FieldOffsetX, FieldOffsetY, FieldOffsetZ;
TString OutputFileName;

public:
R3BTPCSetup(int );
~R3BTPCSetup();
void ReadConfigurationFile(string,int);
inline TString GetOutputFileName(){return OutputFileName;}
inline double GetTargetLength(){return TargetLength;}
inline double GetTargetRadius(){return TargetRadius;}

inline double GetTargetAngle(){return TargetAngle;}
inline double GetTargetOffsetX(){return TargetOffsetX;}
inline double GetTargetOffsetY(){return TargetOffsetY;}
inline double GetTargetOffsetZ(){return TargetOffsetZ;}

inline double GetFieldAngle(){return FieldAngle;}
inline double GetFieldOffsetX(){return FieldOffsetX;}
inline double GetFieldOffsetY(){return FieldOffsetY;}
inline double GetFieldOffsetZ(){return FieldOffsetZ;}

inline double GetGladAngle(){return GladAngle;}
inline double GetGladOffsetX(){return GladOffsetX;}
inline double GetGladOffsetY(){return GladOffsetY;}
inline double GetGladOffsetZ(){return GladOffsetZ;}

ClassDef(R3BTPCSetup,1)
};

#endif

