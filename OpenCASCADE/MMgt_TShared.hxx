// Created on: 1992-10-13
// Created by: Ramin BARRETO, CLE (1994 Standard Light)
// Copyright (c) 1992-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#ifndef _MMgt_TShared_HeaderFile
#define _MMgt_TShared_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Transient.hxx>
class Standard_OutOfMemory;


class MMgt_TShared;
DEFINE_STANDARD_HANDLE(MMgt_TShared, Standard_Transient)


//! Intermediate class between Standard_Transient
//! and descendants.
//! The abstract class TShared is the root class of
//! managed objects. TShared objects are managed
//! by a memory manager based on reference
//! counting. They have handle semantics. In other
//! words, the reference counter is transparently
//! incremented and decremented according to the
//! scope of handles. When all handles, which
//! reference a single object are out of scope, the
//! reference counter becomes null and the object is
//! automatically deleted. The deallocated memory is
//! not given back to the system though. It is
//! reclaimed for new objects of the same size.
//! Warning
//! This memory management scheme does not
//! work for cyclic data structures. In such cases
//! (with back pointers for example), you should
//! interrupt the cycle in a class by using a full C++
//! pointer instead of a handle.
class MMgt_TShared : public Standard_Transient
{

public:

  
  Standard_EXPORT virtual void Delete() const Standard_OVERRIDE;




  DEFINE_STANDARD_RTTIEXT(MMgt_TShared,Standard_Transient)

protected:




private:




};







#endif // _MMgt_TShared_HeaderFile
