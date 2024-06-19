
// TrainingEnglishWordsMemory_by_ZemtsovDlg.h : header file
//

#pragma once


// CTrainingEnglishWordsMemorybyZemtsovDlg dialog
class CTrainingEnglishWordsMemorybyZemtsovDlg : public CDialog
{
// Construction
public:
	CTrainingEnglishWordsMemorybyZemtsovDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAININGENGLISHWORDSMEMORY_BY_ZEMTSOV_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnAboutShortguide();
	afx_msg void OnAboutAboutapplication();
	afx_msg void OnAboutAuthors();
	afx_msg void OnAboutSendfeedback();
};
