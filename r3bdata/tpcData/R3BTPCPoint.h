#ifndef R3BMINOSPOINT_H
#define R3BMINOSPOINT_H


#include "TObject.h"
#include "TVector3.h"
#include "TLorentzVector.h"

#include "FairMCPoint.h"


class R3BTPCPoint : public FairMCPoint 
{

 public:

  /** Default constructor **/
  R3BTPCPoint();

  /** Copy constructor **/
  R3BTPCPoint(const R3BTPCPoint& point) { *this = point; };


  /** Destructor **/
  virtual ~R3BTPCPoint();

  Double_t GetXIn()   const { return fX; }
  Double_t GetYIn()   const { return fY; }
  Double_t GetZIn()   const { return fZ; }
  Double_t GetPxIn() const { return fPx; }
  Double_t GetPyIn() const { return fPy; }
  Double_t GetPzIn() const { return fPz; }


  Double_t GetXOut()  const { return fX_out; }
  Double_t GetYOut()  const { return fY_out; }
  Double_t GetZOut()  const { return fZ_out; }
  Double_t GetPxOut() const { return fPx_out; }
  Double_t GetPyOut() const { return fPy_out; }
  Double_t GetPzOut() const { return fPz_out; }

  void GetPositionIn(TVector3& pos)  { pos.SetXYZ(fX, fY, fZ); }
  void GetPositionIn(TLorentzVector& pos)  { pos.SetXYZT(fX, fY, fZ,fTime); }
  void GetMomentumIn(TVector3& mom) { mom.SetXYZ(fPx,fPy,fPz); }
  void GetMomentumIn(TLorentzVector& mom) { mom.SetPxPyPzE(fPx,fPy,fPz,E); }

  void GetPositionOut(TVector3& pos) { pos.SetXYZ(fX_out,fY_out,fZ_out); }
  void GetPositionOut(TLorentzVector& pos)  { pos.SetXYZT(fX_out, fY_out, fZ_out,fTime_out); }
  void GetMomentumOut(TVector3& mom) { mom.SetXYZ(fPx_out,fPy_out,fPz_out); }
  void GetMomentumOut(TLorentzVector& mom) { mom.SetPxPyPzE(fPx_out,fPy_out,fPz_out,E_out); }


  /** Point coordinates at given z from linear extrapolation **/
  Double_t GetX(Double_t z) const;
  Double_t GetY(Double_t z) const;


  /** Check for distance between in and out **/
  Bool_t IsUsable() const;


  /** Modifiers **/
  void SetPositionIn(TVector3 pos);
  void SetPositionIn(TLorentzVector pos);
  void SetMomentumIn(TVector3 mom);
  void SetMomentumIn(TLorentzVector mom);

  void SetPositionOut(TVector3 pos);
  void SetPositionOut(TLorentzVector pos);
  void SetMomentumOut(TVector3 mom);
  void SetMomentumOut(TLorentzVector mom);

  void SetTimeOut(Double_t time);
  void SetLengthOut(Double_t length);
  void SetPrimaryParticleID(Int_t id);
  void SetParticleName(TString name);

  /** Output to screen **/
  virtual void Print(const Option_t* opt) const;

//  protected:
  public:

  Double_t E;

  Double_t fX_out,  fY_out,  fZ_out;
  Double_t fPx_out, fPy_out, fPz_out,E_out;
  Double_t fTime_out;
  Double_t fLength_out;
  TString  fParticleName;
  Int_t    fPrimaryParticleID;



  ClassDef(R3BTPCPoint,1)

};

//____________________________________________________
inline void R3BTPCPoint::SetPositionIn(TVector3 pos) {
  fX = pos.X();
  fY = pos.Y();
  fZ = pos.Z();
}

//____________________________________________________
inline void R3BTPCPoint::SetPositionIn(TLorentzVector pos) {
  fX = pos.X();
  fY = pos.Y();
  fZ = pos.Z();
  fTime = pos.T();
}
//____________________________________________________
inline void R3BTPCPoint::SetMomentumIn(TVector3 mom) {
  fPx = mom.Px();
  fPy = mom.Py();
  fPz = mom.Pz();
}

//____________________________________________________
inline void R3BTPCPoint::SetMomentumIn(TLorentzVector mom) {
  fPx = mom.Px();
  fPy = mom.Py();
  fPz = mom.Pz();
  E = mom.E();
}
//____________________________________________________
inline void R3BTPCPoint::SetPositionOut(TVector3 pos) {
  fX_out = pos.X();
  fY_out = pos.Y();
  fZ_out = pos.Z();
}
//____________________________________________________
inline void R3BTPCPoint::SetPositionOut(TLorentzVector pos) {
  fX_out = pos.X();
  fY_out = pos.Y();
  fZ_out = pos.Z();
  fTime_out = pos.T();
}


//____________________________________________________
inline void R3BTPCPoint::SetMomentumOut(TVector3 mom) {
  fPx_out = mom.Px();
  fPy_out = mom.Py();
  fPz_out = mom.Pz();
}
//____________________________________________________
inline void R3BTPCPoint::SetMomentumOut(TLorentzVector mom) {
  fPx_out = mom.Px();
  fPy_out = mom.Py();
  fPz_out = mom.Pz();
  E_out = mom.E();
}

//____________________________________________________
inline void R3BTPCPoint::SetTimeOut(Double_t time) {
  fTime_out = time;
}
//____________________________________________________
inline void R3BTPCPoint::SetLengthOut(Double_t length) {
  fLength_out = length;
}
//____________________________________________________
inline void R3BTPCPoint::SetPrimaryParticleID(Int_t id) {
  fPrimaryParticleID = id;
}
//____________________________________________________
inline void R3BTPCPoint::SetParticleName(TString name) {
  fParticleName = name;
}


#endif
