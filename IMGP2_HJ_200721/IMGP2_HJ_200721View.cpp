
// IMGP2_HJ_200721View.cpp: CIMGP2HJ200721View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMGP2_HJ_200721.h"
#endif

#include "IMGP2_HJ_200721Doc.h"
#include "IMGP2_HJ_200721View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMGP2HJ200721View

IMPLEMENT_DYNCREATE(CIMGP2HJ200721View, CView)

BEGIN_MESSAGE_MAP(CIMGP2HJ200721View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMGP2HJ200721View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CIMGP2HJ200721View::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CIMGP2HJ200721View::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CIMGP2HJ200721View::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CIMGP2HJ200721View::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CIMGP2HJ200721View::OnSubConstant)

	ON_COMMAND(ID_MUL_CONSTANT, &CIMGP2HJ200721View::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CIMGP2HJ200721View::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CIMGP2HJ200721View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CIMGP2HJ200721View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CIMGP2HJ200721View::OnXorOperate)
	ON_COMMAND(ID_NEVA_TRANSFORM, &CIMGP2HJ200721View::OnNevaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CIMGP2HJ200721View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CIMGP2HJ200721View::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CIMGP2HJ200721View::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CIMGP2HJ200721View::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CIMGP2HJ200721View::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CIMGP2HJ200721View::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CIMGP2HJ200721View::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CIMGP2HJ200721View::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CIMGP2HJ200721View::OnEmbossing)

	ON_COMMAND(ID_BLURR, &CIMGP2HJ200721View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CIMGP2HJ200721View::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CIMGP2HJ200721View::OnSharpening)
END_MESSAGE_MAP()

// CIMGP2HJ200721View 생성/소멸

CIMGP2HJ200721View::CIMGP2HJ200721View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CIMGP2HJ200721View::~CIMGP2HJ200721View()
{
}

BOOL CIMGP2HJ200721View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CIMGP2HJ200721View 그리기

void CIMGP2HJ200721View::OnDraw(CDC* pDC)
{
	CIMGP2HJ200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int i, j;
	unsigned char R, G, B;
	// 입력 영상 출력
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i * pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 20, i + 20, RGB(R, G, B));
		}
	}
	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 50, i + 20, RGB(R, G, B));
		}
	}
}


// CIMGP2HJ200721View 인쇄


void CIMGP2HJ200721View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMGP2HJ200721View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CIMGP2HJ200721View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CIMGP2HJ200721View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CIMGP2HJ200721View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMGP2HJ200721View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMGP2HJ200721View 진단

#ifdef _DEBUG
void CIMGP2HJ200721View::AssertValid() const
{
	CView::AssertValid();
}

void CIMGP2HJ200721View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMGP2HJ200721Doc* CIMGP2HJ200721View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMGP2HJ200721Doc)));
	return (CIMGP2HJ200721Doc*)m_pDocument;
}
#endif //_DEBUG


// CIMGP2HJ200721View 메시지 처리기


void CIMGP2HJ200721View::OnDownSampling()
{
	// TODO: Add your command handler code here
	CIMGP2HJ200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신
}


void CIMGP2HJ200721View::OnUpSampling()
{
	// TODO: Add your command handler code here
	CIMGP2HJ200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신
}


void CIMGP2HJ200721View::OnQuantization()
{
	// TODO: Add your command handler code here
	CIMGP2HJ200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출
	Invalidate(TRUE); // 화면 갱신
}



void CIMGP2HJ200721View::OnSumConstant()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSumConstant();

	Invalidate(TRUE);
}




void CIMGP2HJ200721View::OnSubConstant()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSubConstant();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnMulConstant()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMulConstant();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnDivConstant()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDivConstant();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnAndOperate()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnOrOperate()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnXorOperate()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnXorOperate();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnNevaTransform()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNevaTransform();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnGammaCorrection()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnBinarization()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarization();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnStressTransform()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnHistoStretch()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnEndInSearch()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndInSearch();

	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnHistogram()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistogram();
	Invalidate(TRUE);
}



void CIMGP2HJ200721View::OnHistoEqual()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnHistoSpec()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoSpec();
	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnEmbossing()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEmbossing();
	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnBlurr()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBlurr();
	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnGaussianFilter()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGaussianFilter();
	Invalidate(TRUE);
}


void CIMGP2HJ200721View::OnSharpening()
{
	CIMGP2HJ200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnSharpening();
	Invalidate(TRUE);
}
