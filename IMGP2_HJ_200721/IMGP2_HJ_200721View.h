
// IMGP2_HJ_200721View.h: CIMGP2HJ200721View 클래스의 인터페이스
//

#pragma once


class CIMGP2HJ200721View : public CView
{
protected: // serialization에서만 만들어집니다.
	CIMGP2HJ200721View() noexcept;
	DECLARE_DYNCREATE(CIMGP2HJ200721View)

// 특성입니다.
public:
	CIMGP2HJ200721Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CIMGP2HJ200721View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
	afx_msg void OnQuantization();
	void OnSumConstant();

	afx_msg void OnSubConstant();
	afx_msg void OnMulConstant();
	afx_msg void OnDivConstant();
	afx_msg void OnAndOperate();
	afx_msg void OnOrOperate();
	afx_msg void OnXorOperate();
	afx_msg void OnNevaTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnStressTransform();
	afx_msg void OnHistoStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
};

#ifndef _DEBUG  // IMGP2_HJ_200721View.cpp의 디버그 버전
inline CIMGP2HJ200721Doc* CIMGP2HJ200721View::GetDocument() const
   { return reinterpret_cast<CIMGP2HJ200721Doc*>(m_pDocument); }
#endif

