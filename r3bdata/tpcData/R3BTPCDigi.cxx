#include "R3BTPCDigi.h"
#include "R3BTPCDatai.h"

#include <iostream>

using std::cout;
using std::endl;
using std::flush;


// -----   Default constructor   -------------------------------------------
R3BTPCDigi::R3BTPCDigi():R3BTPCDatai(){}

// -----   Destructor   ----------------------------------------------------
R3BTPCDigi::~R3BTPCDigi() {}

// -----   Public method Print   -------------------------------------------
void R3BTPCDigi::Print(const Option_t* opt) const {}

//___________
void R3BTPCDigi::ClearEvent(){

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
void R3BTPCDigi::PrintEvent(){

   for(int i=0;i<int(x0.size());i++)
   {
      cout<<"x0,y0,z0:"<<x0.at(i)<<" "<<y0.at(i)<<"  "<<z0.at(i)<<endl;
   }

}

ClassImp(R3BTPCDigi)
