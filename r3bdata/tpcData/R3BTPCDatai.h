#ifndef R3BTPCDATAI_H
#define R3BTPCDATAI_H 1

#include "TObject.h"
#include "TRandom.h"
#include "TMath.h"
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>


using namespace std;

class R3BTPCDatai:public TObject
{
public:
//from simulation
vector<double> x_tpc,y_tpc,z_tpc,e_tpc,s_tpc;
vector<double> x_tar,y_tar,z_tar,e_tar;
vector<double> x_ch,y_ch,z_ch,e_ch;
vector<double> x_win,y_win,z_win,e_win;
vector<double> x_InRoh,y_InRoh,z_InRoh,e_InRoh;
vector<double> x_OutRoh,y_OutRoh,z_OutRoh,e_OutRoh;
vector<double> x_Kap,y_Kap,z_Kap,e_Kap;
double Et_tpc_tot;
double s_tpc_tot;
vector<double> Et_tar,Et_ch,Et_tpc,Et_win,Et_InnerRohacell, Et_OuterRohacell, Et_Kapton;
vector<int> A, Z;

vector<double> x0, y0, z0, theta0, phi0, energy0,momentum0;
vector<int> pdg0;
vector<bool> detection;
int event,vertexcounter;

public:
R3BTPCDatai();
~R3BTPCDatai();
void ClearEvent();

ClassDef(R3BTPCDatai,1)
};

#endif

