
// MFCApplication1View.cpp: CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include <AIS_Line.hxx>

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘图
/*--------------------------------------------------------------------------------------
* @bsimethod                        Method.Jiao                        1/2019
+---------------+---------------+---------------+---------------+---------------+------*/
//绘制图形修改这里
void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	BRepBuilderAPI_MakePolygon MP, MPONE, MPTWO, MPTHREE, MPFIVE;
	//底部一
	MP.Add(gp_Pnt(-51, 0, 0));
	MP.Add(gp_Pnt(-51, 134, 0));
	MP.Add(gp_Pnt(-51, 175, 71));
	MP.Add(gp_Pnt(-51, 175, 97));
	MP.Add(gp_Pnt(-51, 114, 97));
	MP.Add(gp_Pnt(-51, 114, 177));
	MP.Add(gp_Pnt(-51, 0, 177));

	MP.Close();
	TopoDS_Face F = BRepBuilderAPI_MakeFace(MP.Wire());
	if (F.IsNull())
		return;

	gp_Vec aPrimVec(102, 0, 0);
	TopoDS_Shape shapeOne = BRepPrimAPI_MakePrism(F, aPrimVec);
	//中部大面板
	MPONE.Add(gp_Pnt(-124, 114, 97));
	MPONE.Add(gp_Pnt(-124, 288, 97));
	MPONE.Add(gp_Pnt(124, 114, 97));
	MPONE.Add(gp_Pnt(124, 288, 97));
	MPONE.Close();
	TopoDS_Face FONE = BRepBuilderAPI_MakeFace(MPONE.Wire());
	if (FONE.IsNull())
		return;
	gp_Vec aPrimVecOne(0, 0, 80);
	TopoDS_Shape shapeMiddle = BRepPrimAPI_MakePrism(FONE, aPrimVecOne);
	//中部最大面板
	MPTWO.Add(gp_Pnt(-124, 0, 177));
	MPTWO.Add(gp_Pnt(-124, 288, 177));

	MPTWO.Add(gp_Pnt(124, 0, 177));
	MPTWO.Add(gp_Pnt(124, 288, 177));

	MPTWO.Close();
	TopoDS_Face FTWO = BRepBuilderAPI_MakeFace(MPTWO.Wire());
	if (FTWO.IsNull())
		return;
	gp_Vec aPrimVecTwo(0, 0, 10);
	TopoDS_Shape shapeMiddleBig = BRepPrimAPI_MakePrism(FTWO, aPrimVecTwo);
	//顶部梯形


	MPTHREE.Add(gp_Pnt(-124, 0, 187));
	MPTHREE.Add(gp_Pnt(-124, 113, 187));
	MPTHREE.Add(gp_Pnt(-124, 0, 360));
	MPTHREE.Add(gp_Pnt(-124, 40, 360));

	MPTHREE.Close();
	TopoDS_Face FTHREE = BRepBuilderAPI_MakeFace(MPTHREE.Wire());
	if (FTHREE.IsNull())
		return;
	gp_Vec aPrimVecThree(248, 0, 0);
	TopoDS_Shape shapeFour = BRepPrimAPI_MakePrism(FTHREE, aPrimVecThree);

	//两个圆中间的把
	BRepBuilderAPI_MakePolygon MPCON;


	MPCON.Add(gp_Pnt(-95, 174, 97));
	MPCON.Add(gp_Pnt(-95, 226, 97));
	MPCON.Add(gp_Pnt(95, 226, 97));
	MPCON.Add(gp_Pnt(95, 174, 97));

	MPCON.Close();
	TopoDS_Face FCON = BRepBuilderAPI_MakeFace(MPCON.Wire());
	if (FCON.IsNull())
		return;
	gp_Vec aPrimVecCon(0, 0, 90);
	TopoDS_Shape shapeCon = BRepPrimAPI_MakePrism(FCON, aPrimVecCon);


	//最前边的豁口
	MPFIVE.Add(gp_Pnt(-36, 225, 97));
	MPFIVE.Add(gp_Pnt(-36, 288, 97));
	MPFIVE.Add(gp_Pnt(36, 288, 97));
	MPFIVE.Add(gp_Pnt(36, 225, 97));

	MPFIVE.Close();
	TopoDS_Face FFIVE = BRepBuilderAPI_MakeFace(MPFIVE.Wire());
	if (FFIVE.IsNull())
		return;
	gp_Vec aPrimVecFive(0, 0, 90);
	TopoDS_Shape shapeSix = BRepPrimAPI_MakePrism(FFIVE, aPrimVecFive);

	TopoDS_Shape shapeCurOne = BRepAlgoAPI_Fuse(shapeOne, shapeMiddle);
	TopoDS_Shape shapeCurTwo = BRepAlgoAPI_Fuse(shapeCurOne, shapeMiddleBig);
	TopoDS_Shape shapeCurThree = BRepAlgoAPI_Fuse(shapeCurTwo, shapeFour);
	TopoDS_Shape shapeCurFour = BRepAlgoAPI_Cut(shapeCurThree, shapeCon);
	TopoDS_Shape shape = BRepAlgoAPI_Cut(shapeCurFour, shapeSix);

	Handle(AIS_Shape) ais2 = new AIS_Shape(shape);
	GetDocument()->GetAISContext()->SetColor(ais2, Quantity_NOC_BROWN, Standard_False);
	GetDocument()->GetAISContext()->SetMaterial(ais2, Graphic3d_NOM_GOLD, Standard_False);
	//Handle(AIS_Shape) anAISShape = new AIS_Shape(shape);
	pDoc->myAISContext->Display(ais2,true);
	//View()->AutoZFit();
	
}


// CMFCApplication1View 打印


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}

void CMFCApplication1View::OnInitialUpdate()
{
	myView = GetDocument()->GetViewer()->CreateView();
	bool myHlrModeIsOn = Standard_False;
	myView->SetComputedMode(myHlrModeIsOn);

	Handle(Graphic3d_GraphicDriver) theGraphicDriver = ((CMFCApplication1App*)AfxGetApp())->GetGraphicDriver();

	Handle(WNT_Window) aWNTWindow = new WNT_Window(GetSafeHwnd());//,Quantity_NOC_MATRAGRAY);
	myView->SetWindow(aWNTWindow);
	if (!aWNTWindow->IsMapped()) aWNTWindow->Map();
	aWNTWindow->SetBackground(Quantity_NOC_SLATEBLUE2);
	//if(!aWNTWindow->IsMapped()) aWNTWindow->Map();
}

#endif //_DEBUG


// CMFCApplication1View 消息处理程序
