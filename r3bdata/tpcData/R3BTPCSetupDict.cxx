//
// File generated by rootcint at Tue Feb 13 22:33:11 2018

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME R3BTPCSetupDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "R3BTPCSetupDict.h"

#include "TClass.h"
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

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOTShadow {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOTShadow
// END OF SHADOWS

namespace ROOTDict {
   void R3BTPCSetup_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void delete_R3BTPCSetup(void *p);
   static void deleteArray_R3BTPCSetup(void *p);
   static void destruct_R3BTPCSetup(void *p);
   static void streamer_R3BTPCSetup(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::R3BTPCSetup*)
   {
      ::R3BTPCSetup *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::R3BTPCSetup >(0);
      static ::ROOT::TGenericClassInfo 
         instance("R3BTPCSetup", ::R3BTPCSetup::Class_Version(), "./R3BTPCSetup.h", 16,
                  typeid(::R3BTPCSetup), ::ROOT::DefineBehavior(ptr, ptr),
                  &::R3BTPCSetup::Dictionary, isa_proxy, 0,
                  sizeof(::R3BTPCSetup) );
      instance.SetDelete(&delete_R3BTPCSetup);
      instance.SetDeleteArray(&deleteArray_R3BTPCSetup);
      instance.SetDestructor(&destruct_R3BTPCSetup);
      instance.SetStreamerFunc(&streamer_R3BTPCSetup);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::R3BTPCSetup*)
   {
      return GenerateInitInstanceLocal((::R3BTPCSetup*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOTDict

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
   return ::ROOTDict::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int R3BTPCSetup::ImplFileLine()
{
   return ::ROOTDict::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void R3BTPCSetup::Dictionary()
{
   fgIsA = ::ROOTDict::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *R3BTPCSetup::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gCINTMutex); if(!fgIsA) {fgIsA = ::ROOTDict::GenerateInitInstanceLocal((const ::R3BTPCSetup*)0x0)->GetClass();} }
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

//______________________________________________________________________________
void R3BTPCSetup::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class R3BTPCSetup.
      TClass *R__cl = ::R3BTPCSetup::IsA();
      if (R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TargetRadius", &TargetRadius);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TargetLength", &TargetLength);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "ChamberInnerRadius", &ChamberInnerRadius);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "ChamberThickness", &ChamberThickness);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "ChamberLength", &ChamberLength);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "InnerRohacellThickness", &InnerRohacellThickness);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "KaptonThickness", &KaptonThickness);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "OuterRohacellThickness", &OuterRohacellThickness);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TPCRadiusExt", &TPCRadiusExt);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "WindowThickness", &WindowThickness);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TPCLx", &TPCLx);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TPCLy", &TPCLy);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TPCLz", &TPCLz);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TargetAngle", &TargetAngle);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TargetOffsetX", &TargetOffsetX);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TargetOffsetY", &TargetOffsetY);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "TargetOffsetZ", &TargetOffsetZ);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "GladAngle", &GladAngle);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "GladOffsetX", &GladOffsetX);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "GladOffsetY", &GladOffsetY);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "GladOffsetZ", &GladOffsetZ);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "FieldAngle", &FieldAngle);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "FieldOffsetX", &FieldOffsetX);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "FieldOffsetY", &FieldOffsetY);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "FieldOffsetZ", &FieldOffsetZ);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "OutputFileName", &OutputFileName);
      R__insp.InspectMember(OutputFileName, "OutputFileName.");
      TObject::ShowMembers(R__insp);
}

namespace ROOTDict {
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
} // end of namespace ROOTDict for class ::R3BTPCSetup

/********************************************************
* R3BTPCSetupDict.cxx
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableR3BTPCSetupDict();

extern "C" void G__set_cpp_environmentR3BTPCSetupDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("R3BTPCSetup.h");
  G__cpp_reset_tagtableR3BTPCSetupDict();
}
#include <new>
extern "C" int G__cpp_dllrevR3BTPCSetupDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* R3BTPCSetup */
static int G__R3BTPCSetupDict_184_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   R3BTPCSetup* p = NULL;
   char* gvp = (char*) G__getgvp();
   //m: 1
   if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
     p = new R3BTPCSetup((int) G__int(libp->para[0]));
   } else {
     p = new((void*) gvp) R3BTPCSetup((int) G__int(libp->para[0]));
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((R3BTPCSetup*) G__getstructoffset())->ReadConfigurationFile(*((string*) G__int(libp->para[0])), (int) G__int(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      {
         TString* pobj;
         TString xobj = ((R3BTPCSetup*) G__getstructoffset())->GetOutputFileName();
         pobj = new TString(xobj);
         result7->obj.i = (long) ((void*) pobj);
         result7->ref = result7->obj.i;
         G__store_tempobject(*result7);
      }
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetTargetLength());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetTargetRadius());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetTargetAngle());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetTargetOffsetX());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetTargetOffsetY());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetTargetOffsetZ());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetFieldAngle());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetFieldOffsetX());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetFieldOffsetY());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetFieldOffsetZ());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetGladAngle());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetGladOffsetX());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetGladOffsetY());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((R3BTPCSetup*) G__getstructoffset())->GetGladOffsetZ());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) R3BTPCSetup::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_19(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) R3BTPCSetup::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_20(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) R3BTPCSetup::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_21(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      R3BTPCSetup::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_25(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((R3BTPCSetup*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_26(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) R3BTPCSetup::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_27(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) R3BTPCSetup::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_28(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) R3BTPCSetup::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__R3BTPCSetupDict_184_0_29(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) R3BTPCSetup::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__R3BTPCSetupDict_184_0_30(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   R3BTPCSetup* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new R3BTPCSetup(*(R3BTPCSetup*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef R3BTPCSetup G__TR3BTPCSetup;
static int G__R3BTPCSetupDict_184_0_31(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (R3BTPCSetup*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((R3BTPCSetup*) (soff+(sizeof(R3BTPCSetup)*i)))->~G__TR3BTPCSetup();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (R3BTPCSetup*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((R3BTPCSetup*) (soff))->~G__TR3BTPCSetup();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__R3BTPCSetupDict_184_0_32(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   R3BTPCSetup* dest = (R3BTPCSetup*) G__getstructoffset();
   *dest = *(R3BTPCSetup*) libp->para[0].ref;
   const R3BTPCSetup& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* R3BTPCSetup */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncR3BTPCSetupDict {
 public:
  G__Sizep2memfuncR3BTPCSetupDict(): p(&G__Sizep2memfuncR3BTPCSetupDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncR3BTPCSetupDict::*p)();
};

size_t G__get_sizep2memfuncR3BTPCSetupDict()
{
  G__Sizep2memfuncR3BTPCSetupDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceR3BTPCSetupDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup))) {
     R3BTPCSetup *G__Lderived;
     G__Lderived=(R3BTPCSetup*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup),G__get_linked_tagnum(&G__R3BTPCSetupDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableR3BTPCSetupDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* R3BTPCSetup */
static void G__setup_memvarR3BTPCSetup(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup));
   { R3BTPCSetup *p; p=(R3BTPCSetup*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->TargetRadius)-(long)(p)),100,0,0,-1,-1,-1,1,"TargetRadius=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TargetLength)-(long)(p)),100,0,0,-1,-1,-1,1,"TargetLength=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->ChamberInnerRadius)-(long)(p)),100,0,0,-1,-1,-1,1,"ChamberInnerRadius=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->ChamberThickness)-(long)(p)),100,0,0,-1,-1,-1,1,"ChamberThickness=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->ChamberLength)-(long)(p)),100,0,0,-1,-1,-1,1,"ChamberLength=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->InnerRohacellThickness)-(long)(p)),100,0,0,-1,-1,-1,1,"InnerRohacellThickness=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->KaptonThickness)-(long)(p)),100,0,0,-1,-1,-1,1,"KaptonThickness=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->OuterRohacellThickness)-(long)(p)),100,0,0,-1,-1,-1,1,"OuterRohacellThickness=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TPCRadiusExt)-(long)(p)),100,0,0,-1,-1,-1,1,"TPCRadiusExt=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->WindowThickness)-(long)(p)),100,0,0,-1,-1,-1,1,"WindowThickness=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TPCLx)-(long)(p)),100,0,0,-1,-1,-1,1,"TPCLx=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TPCLy)-(long)(p)),100,0,0,-1,-1,-1,1,"TPCLy=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TPCLz)-(long)(p)),100,0,0,-1,-1,-1,1,"TPCLz=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TargetAngle)-(long)(p)),100,0,0,-1,-1,-1,1,"TargetAngle=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TargetOffsetX)-(long)(p)),100,0,0,-1,-1,-1,1,"TargetOffsetX=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TargetOffsetY)-(long)(p)),100,0,0,-1,-1,-1,1,"TargetOffsetY=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->TargetOffsetZ)-(long)(p)),100,0,0,-1,-1,-1,1,"TargetOffsetZ=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->GladAngle)-(long)(p)),100,0,0,-1,-1,-1,1,"GladAngle=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->GladOffsetX)-(long)(p)),100,0,0,-1,-1,-1,1,"GladOffsetX=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->GladOffsetY)-(long)(p)),100,0,0,-1,-1,-1,1,"GladOffsetY=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->GladOffsetZ)-(long)(p)),100,0,0,-1,-1,-1,1,"GladOffsetZ=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->FieldAngle)-(long)(p)),100,0,0,-1,-1,-1,1,"FieldAngle=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->FieldOffsetX)-(long)(p)),100,0,0,-1,-1,-1,1,"FieldOffsetX=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->FieldOffsetY)-(long)(p)),100,0,0,-1,-1,-1,1,"FieldOffsetY=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->FieldOffsetZ)-(long)(p)),100,0,0,-1,-1,-1,1,"FieldOffsetZ=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->OutputFileName)-(long)(p)),117,0,0,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_TString),-1,-1,1,"OutputFileName=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__R3BTPCSetupDictLN_TClass),G__defined_typename("atomic_TClass_ptr"),-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarR3BTPCSetupDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncR3BTPCSetup(void) {
   /* R3BTPCSetup */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup));
   G__memfunc_setup("R3BTPCSetup",959,G__R3BTPCSetupDict_184_0_1, 105, G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup), -1, 0, 1, 1, 1, 0, "i - - 0 - -", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("ReadConfigurationFile",2132,G__R3BTPCSetupDict_184_0_2, 121, -1, -1, 0, 2, 1, 1, 0, 
"u 'string' - 0 - - i - - 0 - -", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetOutputFileName",1714,G__R3BTPCSetupDict_184_0_3, 117, G__get_linked_tagnum(&G__R3BTPCSetupDictLN_TString), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTargetLength",1513,G__R3BTPCSetupDict_184_0_4, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTargetRadius",1519,G__R3BTPCSetupDict_184_0_5, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTargetAngle",1390,G__R3BTPCSetupDict_184_0_6, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTargetOffsetX",1606,G__R3BTPCSetupDict_184_0_7, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTargetOffsetY",1607,G__R3BTPCSetupDict_184_0_8, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetTargetOffsetZ",1608,G__R3BTPCSetupDict_184_0_9, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetFieldAngle",1259,G__R3BTPCSetupDict_184_0_10, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetFieldOffsetX",1475,G__R3BTPCSetupDict_184_0_11, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetFieldOffsetY",1476,G__R3BTPCSetupDict_184_0_12, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetFieldOffsetZ",1477,G__R3BTPCSetupDict_184_0_13, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetGladAngle",1151,G__R3BTPCSetupDict_184_0_14, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetGladOffsetX",1367,G__R3BTPCSetupDict_184_0_15, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetGladOffsetY",1368,G__R3BTPCSetupDict_184_0_16, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("GetGladOffsetZ",1369,G__R3BTPCSetupDict_184_0_17, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__R3BTPCSetupDict_184_0_18, 85, G__get_linked_tagnum(&G__R3BTPCSetupDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&R3BTPCSetup::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__R3BTPCSetupDict_184_0_19, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&R3BTPCSetup::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__R3BTPCSetupDict_184_0_20, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&R3BTPCSetup::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__R3BTPCSetupDict_184_0_21, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&R3BTPCSetup::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__R3BTPCSetupDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__R3BTPCSetupDict_184_0_25, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__R3BTPCSetupDict_184_0_26, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&R3BTPCSetup::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__R3BTPCSetupDict_184_0_27, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&R3BTPCSetup::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__R3BTPCSetupDict_184_0_28, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&R3BTPCSetup::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__R3BTPCSetupDict_184_0_29, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&R3BTPCSetup::DeclFileLine) ), 0);
   // automatic copy constructor
   G__memfunc_setup("R3BTPCSetup", 959, G__R3BTPCSetupDict_184_0_30, (int) ('i'), G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup), -1, 0, 1, 1, 1, 0, "u 'R3BTPCSetup' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~R3BTPCSetup", 1085, G__R3BTPCSetupDict_184_0_31, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__R3BTPCSetupDict_184_0_32, (int) ('u'), G__get_linked_tagnum(&G__R3BTPCSetupDictLN_R3BTPCSetup), -1, 1, 1, 1, 1, 0, "u 'R3BTPCSetup' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncR3BTPCSetupDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {
}

static void G__cpp_setup_global2() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalR3BTPCSetupDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
  G__cpp_setup_global2();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcR3BTPCSetupDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__R3BTPCSetupDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_TString = { "TString" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_string = { "string" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__R3BTPCSetupDictLN_R3BTPCSetup = { "R3BTPCSetup" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableR3BTPCSetupDict() {
  G__R3BTPCSetupDictLN_TClass.tagnum = -1 ;
  G__R3BTPCSetupDictLN_TBuffer.tagnum = -1 ;
  G__R3BTPCSetupDictLN_TMemberInspector.tagnum = -1 ;
  G__R3BTPCSetupDictLN_TObject.tagnum = -1 ;
  G__R3BTPCSetupDictLN_TString.tagnum = -1 ;
  G__R3BTPCSetupDictLN_string.tagnum = -1 ;
  G__R3BTPCSetupDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__R3BTPCSetupDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__R3BTPCSetupDictLN_R3BTPCSetup.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableR3BTPCSetupDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_TString);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_string);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__R3BTPCSetupDictLN_R3BTPCSetup),sizeof(R3BTPCSetup),-1,62464,(char*)NULL,G__setup_memvarR3BTPCSetup,G__setup_memfuncR3BTPCSetup);
}
extern "C" void G__cpp_setupR3BTPCSetupDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupR3BTPCSetupDict()");
  G__set_cpp_environmentR3BTPCSetupDict();
  G__cpp_setup_tagtableR3BTPCSetupDict();

  G__cpp_setup_inheritanceR3BTPCSetupDict();

  G__cpp_setup_typetableR3BTPCSetupDict();

  G__cpp_setup_memvarR3BTPCSetupDict();

  G__cpp_setup_memfuncR3BTPCSetupDict();
  G__cpp_setup_globalR3BTPCSetupDict();
  G__cpp_setup_funcR3BTPCSetupDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncR3BTPCSetupDict();
  return;
}
class G__cpp_setup_initR3BTPCSetupDict {
  public:
    G__cpp_setup_initR3BTPCSetupDict() { G__add_setup_func("R3BTPCSetupDict",(G__incsetup)(&G__cpp_setupR3BTPCSetupDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initR3BTPCSetupDict() { G__remove_setup_func("R3BTPCSetupDict"); }
};
G__cpp_setup_initR3BTPCSetupDict G__cpp_setup_initializerR3BTPCSetupDict;

