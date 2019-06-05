// Created on: 1994-10-13
// Created by: Marc LEGAY
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _RWStl_HeaderFile
#define _RWStl_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>

class StlMesh_Mesh;
class OSD_Path;

//! This package contains the methods to be used in
//! the Stereo Lithograpy Application. The main
//! features of this application are ,starting from a
//! Shape :
//! - mesh this shape with a maximun tolerance,
//! - display the meshing,
//! - write the meshing in a file (binary or ascii),
//! - read of file (binary or ascii) and display it,
//! - translate a binary file to an ascii file,
//! - translate an ascii file to an binary file.
class RWStl 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! write the meshing in a file following the
  //! binary format of an STL file.
  //! Returns false if the cannot be opened;
  Standard_EXPORT static Standard_Boolean WriteBinary (const Handle(StlMesh_Mesh)& aMesh, const OSD_Path& aPath, const Handle(Message_ProgressIndicator)& aProgInd = NULL);
  
  //! write the meshing in a file following the
  //! Ascii  format of an STL file.
  //! Returns false if the cannot be opened;
  Standard_EXPORT static Standard_Boolean WriteAscii (const Handle(StlMesh_Mesh)& aMesh, const OSD_Path& aPath, const Handle(Message_ProgressIndicator)& aProgInd = NULL);
  
  //! This method will chwck if the file is a binary
  //! file or an AsciiFile testing  the 5 first
  //! characters of the file wich are :"solid" in an
  //! ascii file. If we do not find that word we assume
  //! that it is a binary file.
  Standard_EXPORT static Handle(StlMesh_Mesh) ReadFile (const OSD_Path& aPath, const Handle(Message_ProgressIndicator)& aProgInd = NULL);
  
  //! Read a meshing from a binary file
  //! Raises NoMoreObject from Standard if a statement
  //! does not contain the right number of tokens
  //! Raises TypeMisMatch if a token has not the good
  //! type (often real)
  Standard_EXPORT static Handle(StlMesh_Mesh) ReadBinary (const OSD_Path& aPath, const Handle(Message_ProgressIndicator)& aProgInd = NULL);
  
  //! Read a meshing from a binary file
  //! Raises NoMoreObject from Standard if a statement
  //! does not contain the right number of tokens
  //! Raises TypeMisMatch if a token has not the good
  //! type (often real)
  //! Raises MoMoreObject if a file is finished before
  //! having found the word endsolid;
  Standard_EXPORT static Handle(StlMesh_Mesh) ReadAscii (const OSD_Path& aPath, const Handle(Message_ProgressIndicator)& aProgInd = NULL);




protected:





private:





};







#endif // _RWStl_HeaderFile
