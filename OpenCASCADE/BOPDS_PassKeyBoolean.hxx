// Created by: Peter KURNEV
// Copyright (c) 2010-2014 OPEN CASCADE SAS
// Copyright (c) 2007-2010 CEA/DEN, EDF R&D, OPEN CASCADE
// Copyright (c) 2003-2007 OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN, CEDRAT,
//                         EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _BOPDS_PassKeyBoolean_HeaderFile
#define _BOPDS_PassKeyBoolean_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <BOPDS_PassKey.hxx>
#include <BOPCol_BaseAllocator.hxx>



class BOPDS_PassKeyBoolean  : public BOPDS_PassKey
{
public:

  DEFINE_STANDARD_ALLOC

  
    BOPDS_PassKeyBoolean();
virtual ~BOPDS_PassKeyBoolean();
  
    BOPDS_PassKeyBoolean(const BOPCol_BaseAllocator& theAllocator);
  
    BOPDS_PassKeyBoolean(const BOPDS_PassKeyBoolean& Other);
  
    void SetFlag (const Standard_Boolean theFlag);
BOPDS_PassKeyBoolean& operator =(const BOPDS_PassKeyBoolean& );
  
    Standard_Boolean Flag() const;




protected:



  Standard_Boolean myFlag;


private:





};


#include <BOPDS_PassKeyBoolean.lxx>





#endif // _BOPDS_PassKeyBoolean_HeaderFile
