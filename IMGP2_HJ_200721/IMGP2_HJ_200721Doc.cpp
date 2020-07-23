#

// IMGP2_HJ_200721Doc.cpp: CIMGP2HJ200721Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMGP2_HJ_200721.h"
#endif

#include "IMGP2_HJ_200721Doc.h"

#include <propkey.h>
#include "CDownSampleDlg.h" // 대화상자 사용을 위한 헤더 선언
#include "CUPSampleDlg.h"
#include "CQuantizationDlg.h"
#include "math.h"
#include "CConstantDlg.h"
#include "CStressTransformDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIMGP2HJ200721Doc

IMPLEMENT_DYNCREATE(CIMGP2HJ200721Doc, CDocument)

BEGIN_MESSAGE_MAP(CIMGP2HJ200721Doc, CDocument)

	ON_COMMAND(ID_SUB_CONSTANT, &CIMGP2HJ200721Doc::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CIMGP2HJ200721Doc::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CIMGP2HJ200721Doc::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CIMGP2HJ200721Doc::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CIMGP2HJ200721Doc::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CIMGP2HJ200721Doc::OnXorOperate)
	ON_COMMAND(ID_NEVA_TRANSFORM, &CIMGP2HJ200721Doc::OnNevaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CIMGP2HJ200721Doc::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CIMGP2HJ200721Doc::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CIMGP2HJ200721Doc::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CIMGP2HJ200721Doc::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CIMGP2HJ200721Doc::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CIMGP2HJ200721Doc::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CIMGP2HJ200721Doc::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CIMGP2HJ200721Doc::OnHistoSpec)
END_MESSAGE_MAP()


// CIMGP2HJ200721Doc 생성/소멸

CIMGP2HJ200721Doc::CIMGP2HJ200721Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CIMGP2HJ200721Doc::~CIMGP2HJ200721Doc()
{
}

BOOL CIMGP2HJ200721Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CIMGP2HJ200721Doc serialization

void CIMGP2HJ200721Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CIMGP2HJ200721Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CIMGP2HJ200721Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CIMGP2HJ200721Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CIMGP2HJ200721Doc 진단

#ifdef _DEBUG
void CIMGP2HJ200721Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIMGP2HJ200721Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CIMGP2HJ200721Doc 명령


BOOL CIMGP2HJ200721Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CFile File;

	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);

	if (File.GetLength() == 256 * 256)
	{
		m_height = 256;
		m_width = 256;
	}
	else if (File.GetLength() == 512 * 512)
	{
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640*480)
	{
		m_height = 480;
		m_width = 640;
	}
	else
	{
		AfxMessageBox(L"Not Support Image Size");
		return 0;
	}

	m_size = m_width * m_height;
	m_InputImage = new unsigned char[m_size]; // 입력 영상의 크기에 맞는 메모리 할당

	for (int i = 0; i < m_size; i++)
		m_InputImage[i] = 255;

	File.Read(m_InputImage, m_size);
	File.Close();

	return TRUE;
}


BOOL CIMGP2HJ200721Doc::OnSaveDocument(LPCTSTR lpszPathName)
{
	CFile File; // 파일 객체 선언
	CFileDialog SaveDlg(FALSE, L"raw", NULL, OFN_HIDEREADONLY);
	// raw 파일을 다른 이름으로 저장하기를 위한 대화상자 객체 선언
	if (SaveDlg.DoModal() == IDOK) {
		// DoModal 멤버 함수에서 저장하기 수행
		File.Open(SaveDlg.GetPathName(), CFile::modeCreate |
			CFile::modeWrite);
		// 파일 열기
		File.Write(m_InputImage, m_size); // 파일 쓰기
		File.Close(); // 파일 닫기
	}
	return TRUE;
}


void CIMGP2HJ200721Doc::OnDownSampling()
{
	int i, j;
	CDownSampleDlg dlg;
	if (dlg.DoModal() == IDOK) // 대화상자의 활성화 여부
	{
		m_Re_height = m_height / dlg.m_DownSampleRate;
		// 축소 영상의 세로 길이를 계산
		m_Re_width = m_width / dlg.m_DownSampleRate;
		// 축소 영상의 가로 길이를 계산
		m_Re_size = m_Re_height * m_Re_width;
		// 축소 영상의 크기를 계산
		m_OutputImage = new unsigned char[m_Re_size];
		// 축소 영상을 위한 메모리 할당
		for (i = 0; i < m_Re_height; i++) {
			for (j = 0; j < m_Re_width; j++) {
				m_OutputImage[i * m_Re_width + j]
					= m_InputImage[(i * dlg.m_DownSampleRate * m_width) + dlg.m_DownSampleRate * j];
				// 축소 영상을 생성
			}
		}
	}
}

void CIMGP2HJ200721Doc::OnUpSampling()
{
	int i, j;
	CUPSampleDlg dlg;
	if (dlg.DoModal() == IDOK) { // DoModal 대화상자의 활성화 여부
		m_Re_height = m_height * dlg.m_UpSampleRate;
		// 확대 영상의 세로 길이 계산
		m_Re_width = m_width * dlg.m_UpSampleRate;
		// 확대 영상의 가로 길이 계산
		m_Re_size = m_Re_height * m_Re_width;
		// 확대 영상의 크기 계산
		m_OutputImage = new unsigned char[m_Re_size];
		// 확대 영상을 위한 메모리 할당
		for (i = 0; i < m_Re_size; i++)
			m_OutputImage[i] = 0; // 초기화
		for (i = 0; i < m_height; i++) {
			for (j = 0; j < m_width; j++) {
				m_OutputImage[i * dlg.m_UpSampleRate * m_Re_width +
					dlg.m_UpSampleRate * j] = m_InputImage[i * m_width + j];
			} // 재배치하여 영상 확대
		}
	}
}


void CIMGP2HJ200721Doc::OnQuantization()
{
	CQuantizationDlg dlg;
	if (dlg.DoModal() == IDOK)
		// 양자화 비트 수를 결정하는 대화상자의 활성화 여부
	{
		int i, j, value, LEVEL;
		double HIGH, * TEMP;
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;
		m_OutputImage = new unsigned char[m_Re_size];
		// 양자화 처리된 영상을 출력하기 위한 메모리 할당
		TEMP = new double[m_size];
		// 입력 영상 크기(m_size)와 동일한 메모리 할당
		LEVEL = 256; // 입력 영상의 양자화 단계(28=256)
		HIGH = 256.;
		value = (int)pow(2, dlg.m_QuanBit);
		// 양자화 단계 결정(예 : 24=16)
		for (i = 0; i < m_size; i++) {
			for (j = 0; j < value; j++) {
				if (m_InputImage[i] >= (LEVEL / value) * j &&
					m_InputImage[i] < (LEVEL / value) * (j + 1)) {
					TEMP[i] = (double)(HIGH / value) * j; // 양자화 수행
				}
			}
		}
		for (i = 0; i < m_size; i++) {
			m_OutputImage[i] = (unsigned char)TEMP[i];
			// 결과 영상 생성
		}
	}
}


void CIMGP2HJ200721Doc::OnSumConstant()
{
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK){
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] + dlg.m_Constant >= 255)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = (unsigned char)(m_InputImage[i] + dlg.m_Constant);
		}
	}

}



void CIMGP2HJ200721Doc::OnSubConstant()
{
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] - dlg.m_Constant <0)
				m_OutputImage[i] = 0;
			else
				m_OutputImage[i] = (unsigned char)(m_InputImage[i] - dlg.m_Constant);
		}
	}

}


void CIMGP2HJ200721Doc::OnMulConstant()
{
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] * dlg.m_Constant >=255)
				m_OutputImage[i] = 255;
			else if (m_InputImage[i] * dlg.m_Constant < 0)
				m_OutputImage[i] = 0;
			else
				m_OutputImage[i] = (unsigned char)(m_InputImage[i] * dlg.m_Constant);
		}
	}
}


void CIMGP2HJ200721Doc::OnDivConstant()
{
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] * dlg.m_Constant >= 255)
				m_OutputImage[i] = 255;
			else if (m_InputImage[i] / dlg.m_Constant < 0)
				m_OutputImage[i] = 0;
			else
				m_OutputImage[i] = (unsigned char)(m_InputImage[i] / dlg.m_Constant);
		}
	}
}


void CIMGP2HJ200721Doc::OnAndOperate()
{
	CConstantDlg dlg;
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			// 비트 단위 AND 연산
			if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) >= 255)
			{
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) < 0)
			{
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] & (unsigned char)dlg.m_Constant);
			}
		}
	}
}


void CIMGP2HJ200721Doc::OnOrOperate()
{
	CConstantDlg dlg;
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			// 비트 단위 OR 연산
			if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) >= 255)
			{
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) < 0)
			{
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] | (unsigned char)dlg.m_Constant);
			}
		}
	}
}


void CIMGP2HJ200721Doc::OnXorOperate()
{
	CConstantDlg dlg;
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			// 비트 단위 XOR 연산
			if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) >= 255)
			{
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) < 0)
			{
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] ^ (unsigned char)dlg.m_Constant);
			}
		}
	}
}


void CIMGP2HJ200721Doc::OnNevaTransform()
{
	//영상반전전환
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_size; i++)
		m_OutputImage[i] = 255 - m_InputImage[i];
}


void CIMGP2HJ200721Doc::OnGammaCorrection()
{
	//감마보정
	CConstantDlg dlg;

	int i;
	double temp;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			temp = pow(m_InputImage[i], 1 / dlg.m_Constant);

			if (temp < 0)
				m_OutputImage[i] = 0;
			else if (temp > 255)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = (unsigned char)(temp);
		}
	}
	
}


void CIMGP2HJ200721Doc::OnBinarization()
{
	//영상 이진화
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] >= dlg.m_Constant)
				m_OutputImage[i] = 255;
			else

				m_OutputImage[i] = 0;
			}
		}
	}




void CIMGP2HJ200721Doc::OnStressTransform()
{
	//범위 강조 변환
	CStressTransformDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i >= dlg.m_StartPoint && m_InputImage[i <= dlg.m_EndPoint]])
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = m_InputImage[i];
		}
	}
}


void CIMGP2HJ200721Doc::OnHistoStretch()
{

	//히스토그램 stretch
	int i;
	unsigned char LOW, HIGH, MIN, MAX;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	MIN = m_InputImage[0];
	MAX = m_InputImage[0];

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] < MIN)
			MIN = m_InputImage[i];
	}

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] > MAX)
			MAX = m_InputImage[i];
	}

	m_OutputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_size; i++)
		m_OutputImage[i] = (unsigned char)((m_InputImage[i] - MIN) * HIGH / (MAX - MIN));
}


void CIMGP2HJ200721Doc::OnEndInSearch()
{
	int i;
	unsigned char LOW, HIGH, MAX, MIN;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	MIN = m_InputImage[0];
	MAX = m_InputImage[0];

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] < MIN)
			MIN = m_InputImage[i];
	}
	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] > MAX)
			MAX = m_InputImage[i];
	}

	m_OutputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] <= 0)
			m_OutputImage[i] = 0;
		else if (m_InputImage[i] > 255)
			m_OutputImage[i] = 255;
		else
			m_OutputImage[i] = (unsigned char)((m_InputImage[i] - MIN) * HIGH / (MAX - MIN));
	}

}


void CIMGP2HJ200721Doc::OnHistogram()
{
	// Histogram 값은 0~255
	// Histogram 크기 256*256으로 지정

	int i, j, value;
	unsigned char LOW, HIGH;
	double MAX, MIN, DIF;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;
	
	for (i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
	}
	//정규화
	MAX = m_HIST[0];
	MIN = m_HIST[0];

	for (i = 0; i < 256; i++) {
		if (m_HIST[i] > MAX)
			MAX = m_HIST[i];
	}
	for (i = 0; i < 256; i++) {
		if (m_HIST[i] < MIN)
			MIN = m_HIST[i];
	}

	DIF = MAX - MIN;

	// 정규화된 히스토그램
	for (i = 0; i < 256; i++)
		m_Scale_HIST[i] = (unsigned char)((m_HIST[i] - MIN) * HIGH / DIF);
	// 정규화된 히스토그램 출력
	m_OutputImage = new unsigned char[m_Re_size + (256 * 20)];
	for (i = 0; i < m_Re_size; i++)
		m_OutputImage[i] = 255;
	// 정규화된 히스토그램의 값은 출력 배열에 검은 점(0)으로 표현
	for (i = 0; i < 256; i++) {
		for (j = 0; j < m_Scale_HIST[i]; j++) {
			m_OutputImage[m_Re_width * (m_Re_height - j - 1) + i] = 0;
		}
	}
	// 히스토그램을 출력하고 그 아래 부분에 히스토그램의 색을 표시
	for (i = m_Re_height; i < m_Re_height + 5; i++) {
		for (j = 0; j < 256; j++) {
			m_OutputImage[m_Re_height * i + j] = 255;
		}
	}
	for (i = m_Re_height + 5; i < m_Re_height + 20; i++) {
		for (j = 0; j < 256; j++) {
			m_OutputImage[m_Re_height * i + j] = j;
		}
	}
	m_Re_height = m_Re_height + 20;
	m_Re_size = m_Re_height * m_Re_width;


}


void CIMGP2HJ200721Doc::OnHistoEqual()
{
	int i, value;
	unsigned char LOW, HIGH, Temp;
	double SUM = 0.0;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	LOW = 0;
	HIGH = 255;
	// 초기화
	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;
	// 빈도 수 조사
	for (i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
	}
	// 누적 히스토그램 생성
	for (i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
	}
	m_OutputImage = new unsigned char[m_Re_size];
	// 입력 영상을 평활화된 영상으로 출력
	for (i = 0; i < m_size; i++) {
		Temp = m_InputImage[i];
		m_OutputImage[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
	}
}


void CIMGP2HJ200721Doc::OnHistoSpec()
{
	{
		int i, value, Dvalue, top, bottom, DADD;
		unsigned char* m_DTEMP=0, m_Sum_Of_ScHIST[256], m_TABLE[256];
		unsigned char LOW, HIGH, Temp, * m_Org_Temp;
		double m_DHIST[256], m_Sum_Of_DHIST[256], SUM = 0.0, DSUM = 0.0;
		double DMAX, DMIN;
		top = 255;
		bottom = top - 1;


		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];
		m_Org_Temp = new unsigned char[m_size];

		CFile File;
		CFileDialog OpenDlg(TRUE);
		

		// 원하는 히스토그램이 있는 영상을 입력받음
		if (OpenDlg.DoModal() == IDOK) {
			File.Open(OpenDlg.GetPathName(), CFile::modeRead);
			
			if (File.GetLength() == (unsigned)m_size) {
				m_DTEMP = new unsigned char[m_size];
				File.Read(m_DTEMP, m_size);
				File.Close();
			}
			else {
				AfxMessageBox(L"Image size not matched");
				// 같은 크기의 영상을 대상으로 함
				return;
			}
		}
		LOW = 0;
		HIGH = 255;

		// 초기화
		for (i = 0; i < 256; i++) {
			m_HIST[i] = LOW;
			m_DHIST[i] = LOW;
			m_TABLE[i] = LOW;
		}
		// 빈도 수 조사
		for (i = 0; i < m_size; i++) {
			value = (int)m_InputImage[i];
			m_HIST[value]++;
			Dvalue = (int)m_DTEMP[i];
			m_DHIST[Dvalue]++;
		}
		// 누적 히스토그램 조사
		for (i = 0; i < 256; i++) {
			SUM += m_HIST[i];
			m_Sum_Of_HIST[i] = SUM;
			DSUM += m_DHIST[i];
			m_Sum_Of_DHIST[i] = DSUM;
		}
		// 원본 영상의 평활화
		for (i = 0; i < m_size; i++) {
			Temp = m_InputImage[i];
			m_Org_Temp[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
		}
		// 누적 히스토그램에서 최소값과 최대값 지정
		DMIN = m_Sum_Of_DHIST[0];
		DMAX = m_Sum_Of_DHIST[255];
		// 원하는 영상을 평활화
		for (i = 0; i < 256; i++) {
			m_Sum_Of_ScHIST[i] = (unsigned char)((m_Sum_Of_DHIST[i]
				- DMIN) * HIGH / (DMAX - DMIN));
		}
		// 룩업테이블을 이용한 명세화
		for (; ; ) {
			for (i = m_Sum_Of_ScHIST[bottom];
				i <= m_Sum_Of_ScHIST[top]; i++) {
				m_TABLE[i] = top;
			}
			top = bottom;
			bottom = bottom - 1;
			if (bottom < -1)
				break;
		}
		for (i = 0; i < m_size; i++) {
			DADD = (int)m_Org_Temp[i];
			m_OutputImage[i] = m_TABLE[DADD];
		}

	}
}
