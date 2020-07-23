// CUPSampleDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMGP2_HJ_200721.h"
#include "CUPSampleDlg.h"
#include "afxdialogex.h"


// CUPSampleDlg 대화 상자

IMPLEMENT_DYNAMIC(CUPSampleDlg, CDialog)

CUPSampleDlg::CUPSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_UpSampleRate(0)
{

}

CUPSampleDlg::~CUPSampleDlg()
{
}

void CUPSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUPSampleDlg, CDialog)
END_MESSAGE_MAP()


// CUPSampleDlg 메시지 처리기
