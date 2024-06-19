#pragma once


// ABOUTAPPLICATIONCLASS dialog

class ABOUTAPPLICATIONCLASS : public CDialog
{
	DECLARE_DYNAMIC(ABOUTAPPLICATIONCLASS)

public:
	ABOUTAPPLICATIONCLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ABOUTAPPLICATIONCLASS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTAPPLICATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString EC1;
	CString CStringBuffer;
public:
	virtual BOOL OnInitDialog();
};
