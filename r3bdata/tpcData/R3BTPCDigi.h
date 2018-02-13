#ifndef R3BTPCDIGI_H
#define R3BTPCDIGI_H
#include "TObject.h"
#include "TVector3.h"
#include "R3BTPCDatai.h"

class R3BTPCDigi : public R3BTPCDatai
{

 public:

  /** Default constructor **/
  R3BTPCDigi();
  /** Copy constructor **/
  R3BTPCDigi(const R3BTPCDigi& hit) { *this = hit; };

  /** Destructor **/
  virtual ~R3BTPCDigi();

  /** Output to screen **/
  virtual void Print(const Option_t* opt) const;

  vector<double> t0;//track start

  int eventid;
  vector<int> trackid;
  vector<int> tpctrackid;
  vector<int> pdg1;
  vector<int> Z1;
  vector<int> A1;
  vector<double> x1, y1, z1, t1, theta1, phi1, energy1, momentum1;

  vector<int> trackid_tpc;

  void ClearEvent();
  void PrintEvent();

 protected:
 

  ClassDef(R3BTPCDigi, 6)

};

#endif
