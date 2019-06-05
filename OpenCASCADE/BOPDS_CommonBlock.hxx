// Created by: Peter KURNEV
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

#ifndef _BOPDS_CommonBlock_HeaderFile
#define _BOPDS_CommonBlock_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <BOPDS_ListOfPaveBlock.hxx>
#include <BOPCol_ListOfInteger.hxx>
#include <MMgt_TShared.hxx>
#include <BOPCol_BaseAllocator.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
class BOPDS_PaveBlock;


class BOPDS_CommonBlock;
DEFINE_STANDARD_HANDLE(BOPDS_CommonBlock, MMgt_TShared)


//! The class BOPDS_CommonBlock is to store
//! the information about pave blocks that have
//! geometry coincidence (in  terms of a tolerance)  with
//! a) other pave block(s)
//! b) face(s)
class BOPDS_CommonBlock : public MMgt_TShared
{

public:

  

  //! Empty contructor
  Standard_EXPORT BOPDS_CommonBlock();
  

  //! Contructor
  //! <theAllocator> - the allocator to manage the memory
  Standard_EXPORT BOPDS_CommonBlock(const BOPCol_BaseAllocator& theAllocator);
  

  //! Modifier
  //! Adds the pave block <aPB> to the list of pave blocks
  //! of the common block
  Standard_EXPORT void AddPaveBlock (const Handle(BOPDS_PaveBlock)& aPB);
  

  //! Modifier
  //! Adds the list of pave blocks <aLPB>
  //! to the list of pave blocks
  //! of the common block
  Standard_EXPORT void AddPaveBlocks (const BOPDS_ListOfPaveBlock& aLPB);
  

  //! Modifier
  //! Adds the index of the face <aF>
  //! to the list of indices of faces
  //! of the common block
  Standard_EXPORT void AddFace (const Standard_Integer aF);
  

  //! Modifier
  //! Sets the list of indices of faces <aLF>
  //! of the common block
  Standard_EXPORT void SetFaces (const BOPCol_ListOfInteger& aLF);

  //! Modifier
  //! Appends the list of indices of faces <aLF>
  //! to the list of indices of faces
  //! of the common block (the input list is emptied)
  Standard_EXPORT void AppendFaces(BOPCol_ListOfInteger& aLF);


  //! Selector
  //! Returns the list of pave blocks
  //! of the common block
  Standard_EXPORT const BOPDS_ListOfPaveBlock& PaveBlocks() const;
  

  //! Selector
  //! Returns the list of indices of faces
  //! of the common block
  Standard_EXPORT const BOPCol_ListOfInteger& Faces() const;
  

  //! Selector
  //! Returns the first pave block
  //! of the common block
  Standard_EXPORT const Handle(BOPDS_PaveBlock)& PaveBlock1() const;
  

  //! Selector
  //! Returns the pave block that belongs
  //! to the edge with index <theIx>
  Standard_EXPORT Handle(BOPDS_PaveBlock)& PaveBlockOnEdge (const Standard_Integer theIndex);
  

  //! Query
  //! Returns true if the common block contains
  //! a pave block that belongs
  //! to the face with index <theIx>
  Standard_EXPORT Standard_Boolean IsPaveBlockOnFace (const Standard_Integer theIndex) const;
  

  //! Query
  //! Returns true if the common block contains
  //! a pave block that belongs
  //! to the edge with index <theIx>
  Standard_EXPORT Standard_Boolean IsPaveBlockOnEdge (const Standard_Integer theIndex) const;
  

  //! Query
  //! Returns true if the common block contains
  //! a pave block that is equal  to <thePB>
  Standard_EXPORT Standard_Boolean Contains (const Handle(BOPDS_PaveBlock)& thePB) const;
  

  //! Query
  //! Returns true if the common block contains
  //! the face with index equal  to <theF>
  Standard_EXPORT Standard_Boolean Contains (const Standard_Integer theF) const;
  

  //! Modifier
  //! Assign the index <theEdge> as the edge index
  //! to all pave blocks of the common block
  Standard_EXPORT void SetEdge (const Standard_Integer theEdge);
  

  //! Selector
  //! Returns the index of the edge
  //! of  all pave blocks of the common block
  Standard_EXPORT Standard_Integer Edge() const;
  
  Standard_EXPORT void Dump() const;




  DEFINE_STANDARD_RTTIEXT(BOPDS_CommonBlock,MMgt_TShared)

protected:


  BOPDS_ListOfPaveBlock myPaveBlocks;
  BOPCol_ListOfInteger myFaces;


private:




};







#endif // _BOPDS_CommonBlock_HeaderFile
