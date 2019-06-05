// Created on: 1992-01-22
// Created by: GG 
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

#ifndef _V3d_SpotLight_HeaderFile
#define _V3d_SpotLight_HeaderFile

#include <V3d_PositionLight.hxx>
#include <V3d_TypeOfOrientation.hxx>

class V3d_Viewer;
class V3d_SpotLight;
DEFINE_STANDARD_HANDLE(V3d_SpotLight, V3d_PositionLight)

//! Creation and modification of a spot.
class V3d_SpotLight : public V3d_PositionLight
{
public:

  //! Creates a light source of the Spot type in the viewer.
  //! The attenuation factor F which determines
  //! the illumination of a surface depends on the following formula :
  //! F = 1/(theConstAttenuation + theLinearAttenuation*Length)
  //! Length is the distance from the source to the surface.
  //! The default values (1.0,0.0) correspond to a minimum
  //! of attenuation.
  //! The concentration factor determines the dispersion
  //! of the light on the surface, the default value
  //! (1.0) corresponds to a minimum of dispersion.
  //! Warning! raises BadValue from V3d  -
  //! If one of the coefficients is not between 0 and 1.
  //! If the lighting angle is <= 0 or > PI.
  Standard_EXPORT V3d_SpotLight (const Handle(V3d_Viewer)& theViewer,
                                 const V3d_Coordinate theX,
                                 const V3d_Coordinate theY,
                                 const V3d_Coordinate theZ,
                                 const V3d_TypeOfOrientation theDirection = V3d_XnegYnegZpos,
                                 const Quantity_NameOfColor theColor = Quantity_NOC_WHITE,
                                 const Quantity_Coefficient theConstAttenuation = 1.0,
                                 const Quantity_Coefficient theLinearAttenuation = 0.0,
                                 const Quantity_Coefficient theConcentration = 1.0,
                                 const Quantity_PlaneAngle theAngle = 0.523599);
  
  //! Creates a light source of the Spot type in the viewer.
  //! theXt, theYt, theZt : Coordinate of light source Target.
  //! theXp, theYp, theZp : Coordinate of light source Position.
  //! The others parameters describe before.
  //! Warning! raises BadValue from V3d  -
  //! If one of the coefficients is not between 0 and 1.
  //! If the lighting angle is <= 0 or > PI.
  Standard_EXPORT V3d_SpotLight (const Handle(V3d_Viewer)& theViewer,
                                 const V3d_Coordinate theXt,
                                 const V3d_Coordinate theYt,
                                 const V3d_Coordinate theZt,
                                 const V3d_Coordinate theXp,
                                 const V3d_Coordinate theYp,
                                 const V3d_Coordinate theZp,
                                 const Quantity_NameOfColor theColor = Quantity_NOC_WHITE,
                                 const Quantity_Coefficient theConstAttenuation = 1.0,
                                 const Quantity_Coefficient theLinearAttenuation = 0.0,
                                 const Quantity_Coefficient theConcentration = 1.0,
                                 const Quantity_PlaneAngle theAngle = 0.523599);

  //! Defines the position of the light source.
  Standard_EXPORT virtual void SetPosition (const V3d_Coordinate theX,
                                            const V3d_Coordinate theY,
                                            const V3d_Coordinate theZ) Standard_OVERRIDE;

  //! Defines the direction of the light source.
  //! If the normal vector is NULL.
  Standard_EXPORT void SetDirection (const Quantity_Parameter theVx,
                                     const Quantity_Parameter theVy,
                                     const Quantity_Parameter theVz);

  //! Defines the direction of the light source
  //! according to a predefined directional vector.
  Standard_EXPORT void SetDirection (const V3d_TypeOfOrientation theOrientation);

  //! Defines the coefficients of attenuation.
  //! Warning! raises BadValue from V3d
  //! if one of the coefficient is < 0 or > 1.
  Standard_EXPORT void SetAttenuation (const Quantity_Coefficient theConstAttenuation,
                                       const Quantity_Coefficient theLinearAttenuation);

  //! Defines the coefficient of concentration.
  //! if the coefficient is < 0 or > 1.
  Standard_EXPORT void SetConcentration (const Quantity_Coefficient theConcentration);

  //! Defines the spot angle in RADIANS.
  //! Warning: raises BadValue from from V3d
  //! If the angle is <= 0 or > PI.
  Standard_EXPORT void SetAngle (const Quantity_PlaneAngle theAngle);

  //! Display the graphic structure of light source
  //! in the chosen view. We have three type of representation
  //! - SIMPLE   : Only the light source is displayed.
  //! - PARTIAL  : The light source and the light space are
  //! displayed.
  //! - COMPLETE : The light source, the light space and the
  //! radius of light space are displayed.
  //! We can choose the "SAMELAST" as parameter of representation
  //! In this case the graphic structure representation will be
  //! the last displayed.
  Standard_EXPORT void Display (const Handle(V3d_View)& theView,
                                const V3d_TypeOfRepresentation theRepresentation) Standard_OVERRIDE;

  //! Returns the direction of the light source defined by theVx, theVy, theVz.
  Standard_EXPORT void Direction (Quantity_Parameter& theVx,
                                  Quantity_Parameter& theVy,
                                  Quantity_Parameter& theVz) const;

  //! Returns the position of the light source.
  Standard_EXPORT void Position (V3d_Coordinate& theX,
                                 V3d_Coordinate& theY,
                                 V3d_Coordinate& theZ) const Standard_OVERRIDE;

  //! Returns the attenuation factors A1,A2 of the light source.
  Standard_EXPORT void Attenuation (Quantity_Coefficient& theConstAttentuation,
                                    Quantity_Coefficient& theLinearAttentuation) const;

  Standard_EXPORT Quantity_Coefficient Concentration() const;

  //! Returns the spot angle.
  Standard_EXPORT Quantity_PlaneAngle Angle() const;

  DEFINE_STANDARD_RTTIEXT(V3d_SpotLight,V3d_PositionLight)

private:

  //! Defines the representation of the spot light source.
  Standard_EXPORT void Symbol (const Handle(Graphic3d_Group)& theSymbol,
                               const Handle(V3d_View)& theView) const Standard_OVERRIDE;
};

#endif // _V3d_SpotLight_HeaderFile
