#pragma once


// ERRORWINDOWCLASS dialog

class ERRORWINDOWCLASS : public CDialog
{
	DECLARE_DYNAMIC(ERRORWINDOWCLASS)

public:
	ERRORWINDOWCLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ERRORWINDOWCLASS();

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
	bool fg1 = false; 
public:
	CString afx_msg ReadErrorType(int x);
	virtual BOOL OnInitDialog();
};
