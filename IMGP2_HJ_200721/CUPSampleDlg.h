#pragma once


// CUPSampleDlg 대화 상자

class CUPSampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CUPSampleDlg)

public:
	CUPSampleDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUPSampleDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_UpSampleRate;
};
