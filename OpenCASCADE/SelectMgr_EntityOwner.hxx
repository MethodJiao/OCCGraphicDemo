// Created on: 1995-05-23
// Created by: Robert COUBLANC
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _SelectMgr_EntityOwner_HeaderFile
#define _SelectMgr_EntityOwner_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <SelectMgr_SOPtr.hxx>
#include <Standard_Boolean.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_Integer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Graphic3d_HighlightStyle.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <SelectMgr_SelectableObject.hxx>
class Standard_NoSuchObject;
class PrsMgr_PresentationManager;
class TopLoc_Location;
class V3d_Viewer;


class SelectMgr_EntityOwner;
DEFINE_STANDARD_HANDLE(SelectMgr_EntityOwner, SelectBasics_EntityOwner)

//! A framework to define classes of owners of sensitive primitives.
//! The owner is the link between application and
//! selection data structures.
//! For the application to make its own objects selectable,
//! it must define owner classes inheriting this framework.
class SelectMgr_EntityOwner : public SelectBasics_EntityOwner
{

public:

  
  //! Initializes the selection priority aPriority.
  Standard_EXPORT SelectMgr_EntityOwner(const Standard_Integer aPriority = 0);
  
  //! Constructs a framework with the selectable object
  //! anSO being attributed the selection priority aPriority.
  Standard_EXPORT SelectMgr_EntityOwner(const Handle(SelectMgr_SelectableObject)& aSO, const Standard_Integer aPriority = 0);
  
  //! Constructs a framework from existing one
  //! anSO being attributed the selection priority aPriority.
  Standard_EXPORT SelectMgr_EntityOwner(const Handle(SelectMgr_EntityOwner)& theOwner, const Standard_Integer aPriority = 0);
  
  //! Returns true if there is a selectable object to serve as an owner.
  Standard_EXPORT Standard_Boolean HasSelectable() const;
  
  //! Returns a selectable object detected in the working context.
  Standard_EXPORT virtual Handle(SelectMgr_SelectableObject) Selectable() const;
  
  //! Sets the selectable object anSO to be used by the
  //! second constructor above.
  Standard_EXPORT void Set (const Handle(SelectMgr_SelectableObject)& aSO);
  
  //! Returns true if the presentation manager aPM
  //! highlights selections corresponding to the selection mode aMode.
  Standard_EXPORT virtual Standard_Boolean IsHilighted (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0) const;
  
  //! Highlights selectable object's presentation with mode theMode in presentation manager
  //! with given highlight style. Also a check for auto-highlight is performed - if
  //! selectable object manages highlighting on its own, execution will be passed to
  //! SelectMgr_SelectableObject::HilightOwnerWithColor method
  Standard_EXPORT virtual void HilightWithColor (const Handle(PrsMgr_PresentationManager3d)& thePM,
                                                 const Handle(Graphic3d_HighlightStyle)& theStyle,
                                                 const Standard_Integer theMode = 0);
  
  //! Removes highlighting from the owner of a detected
  //! selectable object in the presentation manager aPM.
  //! This object could be the owner of a sensitive primitive.
  //! The display mode for the highlight is aMode; this has
  //! the default value of 0, that is, wireframe mode.
  Standard_EXPORT virtual void Unhilight (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0);
  
  //! Clears the owners matching the value of the selection
  //! mode aMode from the presentation manager object aPM.
  Standard_EXPORT virtual void Clear (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0);
  
  Standard_EXPORT virtual Standard_Boolean HasLocation() const Standard_OVERRIDE;
  
  Standard_EXPORT virtual void SetLocation (const TopLoc_Location& aLoc) Standard_OVERRIDE;
  
  Standard_EXPORT virtual void ResetLocation() Standard_OVERRIDE;
  
  Standard_EXPORT virtual TopLoc_Location Location() const Standard_OVERRIDE;
  
  //! Set the state of the owner.
  //! @param theIsSelected [in] shows if owner is selected.
    void SetSelected (const Standard_Boolean theIsSelected);
  
  //! @return Standard_True if the owner is selected.
    Standard_Boolean IsSelected() const;
  
  //! Set the state of the owner.
  //! The method is deprecated. Use SetSelected() instead.
    void State (const Standard_Integer aStatus);
  
    Standard_Integer State() const;
  
  //! if owner is not auto hilighted, for group contains many such owners
  //! will be called one method HilightSelected of SelectableObject
  Standard_EXPORT virtual Standard_Boolean IsAutoHilight() const;
  
  //! if this method returns TRUE the owner will allways call method
  //! Hilight for SelectableObject when the owner is detected. By default
  //! it always return FALSE.
  Standard_EXPORT virtual Standard_Boolean IsForcedHilight() const;
  
  //! Set Z layer ID and update all presentations.
  Standard_EXPORT virtual void SetZLayer (const Graphic3d_ZLayerId theLayerId);

  //! Implements immediate application of location transformation of parent object to dynamic highlight structure
  Standard_EXPORT virtual void UpdateHighlightTrsf (const Handle(V3d_Viewer)& theViewer,
                                                    const Handle(PrsMgr_PresentationManager3d)& theManager,
                                                    const Standard_Integer theDispMode);

  //! Returns true if pointer to selectable object of this owner is equal to the given one
  Standard_Boolean IsSameSelectable (const Handle(SelectMgr_SelectableObject)& theOther) const
  {
    return mySelectable == theOther.get();
  }


  DEFINE_STANDARD_RTTIEXT(SelectMgr_EntityOwner,SelectBasics_EntityOwner)

protected:




private:


  SelectMgr_SOPtr mySelectable;
  Standard_Boolean myIsSelected;


};


#include <SelectMgr_EntityOwner.lxx>





#endif // _SelectMgr_EntityOwner_HeaderFile
