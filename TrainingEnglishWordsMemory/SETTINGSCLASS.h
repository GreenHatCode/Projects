#pragma once


// SETTINGSCLASS dialog

class SETTINGSCLASS : public CDialog
{
	DECLARE_DYNAMIC(SETTINGSCLASS)

public:
	SETTINGSCLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SETTINGSCLASS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	BOOL ShowIncorrectWordsAmount;
	BOOL ShowTranslatedWordsAmount;
	BOOL EndlessMode;
	BOOL RepeatWordWithMistake;

	CString ms, t;
	bool ShowIncorrectWordsAmountInner;
	bool ShowTranslatedWordsAmountInner;
	bool EndlessModeInner;
	bool RepeatWordWithMistakeInner;
};
