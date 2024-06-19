#pragma once


// SHORTGUIDECLASS dialog

class SHORTGUIDECLASS : public CDialog
{
	DECLARE_DYNAMIC(SHORTGUIDECLASS)

public:
	SHORTGUIDECLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SHORTGUIDECLASS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHORTGUIDE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int n = 2; // counter
	CStatic E1; // picture control's varible 
	afx_msg void OnBnClickedButton1();
};
