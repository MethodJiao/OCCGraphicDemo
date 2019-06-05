// Created on: 2007-08-17
// Created by: Sergey ZARITCHNY
// Copyright (c) 2007-2014 OPEN CASCADE SAS
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

#ifndef _TDataStd_HDataMapOfStringReal_HeaderFile
#define _TDataStd_HDataMapOfStringReal_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TDataStd_DataMapOfStringReal.hxx>
#include <MMgt_TShared.hxx>
#include <Standard_Integer.hxx>


class TDataStd_HDataMapOfStringReal;
DEFINE_STANDARD_HANDLE(TDataStd_HDataMapOfStringReal, MMgt_TShared)

//! Extension of TDataStd_DataMapOfStringReal class
//! to be manipulated by handle.
class TDataStd_HDataMapOfStringReal : public MMgt_TShared
{

public:

  
  Standard_EXPORT TDataStd_HDataMapOfStringReal(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT TDataStd_HDataMapOfStringReal(const TDataStd_DataMapOfStringReal& theOther);
  
    const TDataStd_DataMapOfStringReal& Map() const;
  
    TDataStd_DataMapOfStringReal& ChangeMap();




  DEFINE_STANDARD_RTTIEXT(TDataStd_HDataMapOfStringReal,MMgt_TShared)

protected:




private:


  TDataStd_DataMapOfStringReal myMap;


};


#include <TDataStd_HDataMapOfStringReal.lxx>





#endif // _TDataStd_HDataMapOfStringReal_HeaderFile
