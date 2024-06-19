#pragma once


// AUTHORSCLASS dialog

class AUTHORSCLASS : public CDialog
{
	DECLARE_DYNAMIC(AUTHORSCLASS)

public:
	AUTHORSCLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AUTHORSCLASS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTHORS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString E2;
	CString CStringBuffer;
	virtual BOOL OnInitDialog();
};
