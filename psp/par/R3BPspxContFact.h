/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----               R3BPspxContFact header file                   -----
// -----                 Created 16/05/12  by I.Syndikus               -----
// -------------------------------------------------------------------------

#ifndef R3BPSPXCONTFACT_H
#define R3BPSPXCONTFACT_H

#include "FairContFact.h"

class FairContainer;

/**
 * Container Factory for Parameters of PSPX detectors.
 * @author Ina Syndikus
 * @since May 12, 2016
 */

class R3BPspxContFact : public FairContFact
{
  private:
    void setAllContainers();

  public:
    /** Default Constructor (called when the library is loaded) **/
    R3BPspxContFact();
    /** Destructor **/
    ~R3BPspxContFact() {}

    FairParSet* createContainer(FairContainer*);

    ClassDef(R3BPspxContFact, 1) // Factory for all Pspx parameter containers
};

#endif /* !R3BPSPXCONTFACT_H */
