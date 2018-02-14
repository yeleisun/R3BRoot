// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME R3BTPCSetupDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "R3BTPCSetup.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_R3BTPCSetup(void *p);
   static void deleteArray_R3BTPCSetup(void *p);
   static void destruct_R3BTPCSetup(void *p);
   static void streamer_R3BTPCSetup(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::R3BTPCSetup*)
   {
      ::R3BTPCSetup *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::R3BTPCSetup >(0);
      static ::ROOT::TGenericClassInfo 
         instance("R3BTPCSetup", ::R3BTPCSetup::Class_Version(), "R3BTPCSetup.h", 15,
                  typeid(::R3BTPCSetup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::R3BTPCSetup::Dictionary, isa_proxy, 16,
                  sizeof(::R3BTPCSetup) );
      instance.SetDelete(&delete_R3BTPCSetup);
      instance.SetDeleteArray(&deleteArray_R3BTPCSetup);
      instance.SetDestructor(&destruct_R3BTPCSetup);
      instance.SetStreamerFunc(&streamer_R3BTPCSetup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::R3BTPCSetup*)
   {
      return GenerateInitInstanceLocal((::R3BTPCSetup*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr R3BTPCSetup::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *R3BTPCSetup::Class_Name()
{
   return "R3BTPCSetup";
}

//______________________________________________________________________________
const char *R3BTPCSetup::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int R3BTPCSetup::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *R3BTPCSetup::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *R3BTPCSetup::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void R3BTPCSetup::Streamer(TBuffer &R__b)
{
   // Stream an object of class R3BTPCSetup.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> TargetRadius;
      R__b >> TargetLength;
      R__b >> ChamberInnerRadius;
      R__b >> ChamberThickness;
      R__b >> ChamberLength;
      R__b >> InnerRohacellThickness;
      R__b >> KaptonThickness;
      R__b >> OuterRohacellThickness;
      R__b >> TPCRadiusExt;
      R__b >> WindowThickness;
      R__b >> TPCLx;
      R__b >> TPCLy;
      R__b >> TPCLz;
      R__b >> TargetAngle;
      R__b >> TargetOffsetX;
      R__b >> TargetOffsetY;
      R__b >> TargetOffsetZ;
      R__b >> GladAngle;
      R__b >> GladOffsetX;
      R__b >> GladOffsetY;
      R__b >> GladOffsetZ;
      R__b >> FieldAngle;
      R__b >> FieldOffsetX;
      R__b >> FieldOffsetY;
      R__b >> FieldOffsetZ;
      OutputFileName.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, R3BTPCSetup::IsA());
   } else {
      R__c = R__b.WriteVersion(R3BTPCSetup::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << TargetRadius;
      R__b << TargetLength;
      R__b << ChamberInnerRadius;
      R__b << ChamberThickness;
      R__b << ChamberLength;
      R__b << InnerRohacellThickness;
      R__b << KaptonThickness;
      R__b << OuterRohacellThickness;
      R__b << TPCRadiusExt;
      R__b << WindowThickness;
      R__b << TPCLx;
      R__b << TPCLy;
      R__b << TPCLz;
      R__b << TargetAngle;
      R__b << TargetOffsetX;
      R__b << TargetOffsetY;
      R__b << TargetOffsetZ;
      R__b << GladAngle;
      R__b << GladOffsetX;
      R__b << GladOffsetY;
      R__b << GladOffsetZ;
      R__b << FieldAngle;
      R__b << FieldOffsetX;
      R__b << FieldOffsetY;
      R__b << FieldOffsetZ;
      OutputFileName.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_R3BTPCSetup(void *p) {
      delete ((::R3BTPCSetup*)p);
   }
   static void deleteArray_R3BTPCSetup(void *p) {
      delete [] ((::R3BTPCSetup*)p);
   }
   static void destruct_R3BTPCSetup(void *p) {
      typedef ::R3BTPCSetup current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_R3BTPCSetup(TBuffer &buf, void *obj) {
      ((::R3BTPCSetup*)obj)->::R3BTPCSetup::Streamer(buf);
   }
} // end of namespace ROOT for class ::R3BTPCSetup

namespace {
  void TriggerDictionaryInitialization_R3BTPCSetupDict_Impl() {
    static const char* headers[] = {
"R3BTPCSetup.h",
0
    };
    static const char* includePaths[] = {
"/home/gpfs/manip/mnt0607/structurenucleaire/ysun/gsi/2018/FairSoft_install/include/root",
"/home/gpfs/manip/mnt0607/structurenucleaire/ysun/gsi/2018/R3BRoot/r3bdata/tpcData/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "R3BTPCSetupDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$R3BTPCSetup.h")))  R3BTPCSetup;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "R3BTPCSetupDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "R3BTPCSetup.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"R3BTPCSetup", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("R3BTPCSetupDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_R3BTPCSetupDict_Impl, {}, classesHeaders, /*has C++ module?*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_R3BTPCSetupDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_R3BTPCSetupDict() {
  TriggerDictionaryInitialization_R3BTPCSetupDict_Impl();
}
