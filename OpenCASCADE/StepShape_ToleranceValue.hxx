// Created on: 2001-04-24
// Created by: Christian CAILLET
// Copyright (c) 2001-2014 OPEN CASCADE SAS
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

#ifndef _StepShape_ToleranceValue_HeaderFile
#define _StepShape_ToleranceValue_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <MMgt_TShared.hxx>
class StepBasic_MeasureWithUnit;


class StepShape_ToleranceValue;
DEFINE_STANDARD_HANDLE(StepShape_ToleranceValue, MMgt_TShared)

//! Added for Dimensional Tolerances
class StepShape_ToleranceValue : public MMgt_TShared
{

public:

  
  Standard_EXPORT StepShape_ToleranceValue();
  
  Standard_EXPORT void Init (const Handle(StepBasic_MeasureWithUnit)& lower_bound, const Handle(StepBasic_MeasureWithUnit)& upper_bound);
  
  Standard_EXPORT Handle(StepBasic_MeasureWithUnit) LowerBound() const;
  
  Standard_EXPORT void SetLowerBound (const Handle(StepBasic_MeasureWithUnit)& lower_bound);
  
  Standard_EXPORT Handle(StepBasic_MeasureWithUnit) UpperBound() const;
  
  Standard_EXPORT void SetUpperBound (const Handle(StepBasic_MeasureWithUnit)& upper_bound);




  DEFINE_STANDARD_RTTIEXT(StepShape_ToleranceValue,MMgt_TShared)

protected:




private:


  Handle(StepBasic_MeasureWithUnit) theLowerBound;
  Handle(StepBasic_MeasureWithUnit) theUpperBound;


};







#endif // _StepShape_ToleranceValue_HeaderFile
