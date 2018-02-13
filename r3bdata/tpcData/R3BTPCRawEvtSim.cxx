#include "R3BTPCRawEvtSim.h"
#include "R3BTPCDatai.h"

#include <iostream>

using std::cout;
using std::endl;
using std::flush;


// -----   Default constructor   -------------------------------------------
R3BTPCRawEvtSim::R3BTPCRawEvtSim():R3BTPCDatai(){}

// -----   Destructor   ----------------------------------------------------
R3BTPCRawEvtSim::~R3BTPCRawEvtSim() {}

// -----   Public method Print   -------------------------------------------
void R3BTPCRawEvtSim::Print(const Option_t* opt) const {}

//___________
void R3BTPCRawEvtSim::ClearEvent(){

     R3BTPCDatai::ClearEvent();


     eventid = -1;
     //each track
     trackid.clear();
     tpctrackid.clear();

     //each track
     t0.clear();

     //each track end
     Z1.clear();
     A1.clear();
     pdg1.clear();
     x1.clear();
     y1.clear();
     z1.clear();
     t1.clear();
     theta1.clear();
     phi1.clear();
     energy1.clear();
     momentum1.clear();

     //each hit in tpc has a trackid
     trackid_tpc.clear();
}
// -------------------------------------------------------------------------
void R3BTPCRawEvtSim::PrintEvent(){

   for(int i=0;i<int(x0.size());i++)
   {
      cout<<"x0,y0,z0:"<<x0.at(i)<<" "<<y0.at(i)<<"  "<<z0.at(i)<<endl;
   }

}

ClassImp(R3BTPCRawEvtSim)
