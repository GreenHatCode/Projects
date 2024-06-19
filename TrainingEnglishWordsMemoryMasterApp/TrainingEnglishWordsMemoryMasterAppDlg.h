
// TrainingEnglishWordsMemoryMasterApp2.0Dlg.h : header file
//

#pragma once


// CTrainingEnglishWordsMemoryMasterApp20Dlg dialog
class CTrainingEnglishWordsMemoryMasterApp20Dlg : public CDialog
{
// Construction
public:
	CTrainingEnglishWordsMemoryMasterApp20Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAININGENGLISHWORDSMEMORYMASTERAPP20_DIALOG };
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
	virtual void OnOK();
private:
	CString InputFilename;
	CString Text;
	CString UserFilename, UserText;
	CString Buffer1, Buffer2, Buffer3;
	bool fg1 = false;
	bool fg2 = false;
	int fg1_integer = 0;
	CString CstringBufferName;

	afx_msg void OnAboutShortguide();
	afx_msg void OnAboutAboutapplication();
	afx_msg void OnAboutAuthors();
	afx_msg void OnFileOpen32775();
	afx_msg void OnFileClose32776();
	afx_msg void OnSavechanges();

	afx_msg CString ReplacingSpaceInString(CString CString_Buffer1);
	afx_msg void WriteOutputInFile(CString User_input_file_name);
};
