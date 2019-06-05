
// MFCApplication1Doc.h: CMFCApplication1Doc 类的接口
//


#pragma once


class CMFCApplication1Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCApplication1Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// 特性
public:

// 操作
public:
	Handle_V3d_Viewer myViewer;
	Handle_AIS_InteractiveContext myAISContext;

	Handle(V3d_Viewer) GetViewer() { return myViewer; }
	Handle(AIS_InteractiveContext)& GetAISContext() { return myAISContext; }
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
