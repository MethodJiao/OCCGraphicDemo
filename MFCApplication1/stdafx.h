
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持




#include <V3d_View.hxx>               //V3d_View
#include <WNT_Window.hxx>             //Handle_WNT_Window
//#include <Graphic3d.hxx>              //Graphic3d/InitGraphicDriver
#include <AIS_InteractiveContext.hxx> //AIS_InteractiveContext
#include <AIS_Shape.hxx>              //Handle_AIS_Shape
#include <Standard.hxx>
#include <Standard_PrimitiveTypes.hxx>

#include <AIS_InteractiveContext.hxx>
#include <AIS_Line.hxx>
#include <AIS_Shape.hxx>
#include <AIS_Point.hxx>
#include <AIS_TexturedShape.hxx>
#include <Aspect_Grid.hxx>
#include <Aspect_PolygonOffsetMode.hxx>
#include <Aspect_DisplayConnection.hxx>


#include <gp.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Pln.hxx>
#include <gp.hxx>
#include <gp_Pnt2d.hxx>

#include <Geom_CylindricalSurface.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Surface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <GeomLib.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>

#include <Geom_CartesianPoint.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Geom2d_Circle.hxx>
#include <GeomAPI_ProjectPointOnCurve.hxx>

#include <GCPnts_QuasiUniformDeflection.hxx>

#include <Graphic3d_Group.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_Texture1Dsegment.hxx>


#include <OpenGl_GraphicDriver.hxx>
#include <Prs3d_Root.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_IsoAspect.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Prs3d_Presentation.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Prs3d_Text.hxx>

#include <Select3D_SensitiveBox.hxx>
#include <Select3D_SensitiveCurve.hxx>
#include <Select3D_SensitiveGroup.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <ShapeBuild_Edge.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <StdPrs_ShadedShape.hxx>
#include <StdPrs_HLRPolyShape.hxx>
#include <StdSelect_BRepSelectionTool.hxx>
#include <StdPrs_WFShape.hxx>
#include <StdPrs_ToolRFace.hxx>
#include <StdSelect.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <StdSelect_BRepSelectionTool.hxx>

#include <TCollection_AsciiString.hxx>
#include "TopExp.hxx"
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Builder.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_ListOfShape.hxx>
#include <TopoDS_ListIteratorOfListOfShape.hxx>
#include <TopoDS_Iterator.hxx>
#include "TopoDS_Edge.hxx"
#include "TopoDS_Vertex.hxx"
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>

#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <WNT_Window.hxx>


#include <BRepAlgoAPI_Fuse.hxx>

#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>

#include <BRepFilletAPI_MakeFillet.hxx>

#include <BRepLib.hxx>

#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>

#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakePrism.hxx>

#include <BRep_Tool.hxx>
#include <BRepTools.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepBndLib.hxx>
#include <BRepAdaptor_HArray1OfCurve.hxx>
#include <BRepAdaptor_Curve2d.hxx>


#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeSegment.hxx>
#include <TopTools_ListOfShape.hxx>
#include <GProp_PEquation.hxx>

#include <math_Matrix.hxx>
#include <gce_MakeCirc.hxx>
#include <geom2d_line.hxx>

#include <GCE2d_MakeSegment.hxx>
#include <TopExp_Explorer.hxx>
#include "BRepAlgoAPI_Cut.hxx"





#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


