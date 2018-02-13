#include "R3BTPCDatai.h"
ClassImp(R3BTPCDatai)

R3BTPCDatai::R3BTPCDatai(){
}

R3BTPCDatai::~R3BTPCDatai(){
}

void R3BTPCDatai::ClearEvent(){
x_tpc.clear();
y_tpc.clear();
z_tpc.clear();
e_tpc.clear();
s_tpc.clear();

x_tar.clear();
y_tar.clear();
z_tar.clear();
e_tar.clear();

x_win.clear();
y_win.clear();
z_win.clear();
e_win.clear();

x_ch.clear();
y_ch.clear();
z_ch.clear();
e_ch.clear();

x_InRoh.clear();
y_InRoh.clear();
z_InRoh.clear();
e_InRoh.clear();

x_OutRoh.clear();
y_OutRoh.clear();
z_OutRoh.clear();
e_OutRoh.clear();

x_Kap.clear();
y_Kap.clear();
z_Kap.clear();
e_Kap.clear();


Et_tpc_tot=0.;
s_tpc_tot=0.;


Et_tar.clear();
Et_ch.clear();
Et_win.clear();
Et_tpc.clear();
Et_InnerRohacell.clear();
Et_OuterRohacell.clear();
Et_Kapton.clear();

x0.clear();
y0.clear();
z0.clear();
theta0.clear();
phi0.clear();
energy0.clear();
momentum0.clear();
pdg0.clear();

A.clear();
Z.clear();
detection.clear();
event = 0;
vertexcounter = 0;

}

