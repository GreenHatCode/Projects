#pragma once


// ERRORWINDOW dialog

class ERRORWINDOW : public CDialog
{
	DECLARE_DYNAMIC(ERRORWINDOW)

public:
	ERRORWINDOW(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ERRORWINDOW();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ERRORWINDOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString E2;
	int ErrorType = 0;
	CString messageE2;
	CString CStringBuffer;
	bool fg1 = false; // program found the start of description in settings.txt
public:
	CString afx_msg ReadErrorType(int x);
	virtual BOOL OnInitDialog();
};
