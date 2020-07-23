// CQuantizationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMGP2_HJ_200721.h"
#include "CQuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg 대화 상자

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialog)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, m_QuanBit(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuanBit);
	DDV_MinMaxInt(pDX, m_QuanBit, 1, 8);
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialog)
END_MESSAGE_MAP()


// CQuantizationDlg 메시지 처리기
