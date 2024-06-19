#pragma once


// CHANGEFILECLASS dialog

class CHANGEFILECLASS : public CDialog
{
	DECLARE_DYNAMIC(CHANGEFILECLASS)

public:
	CHANGEFILECLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHANGEFILECLASS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEFILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString FileName;
	CString InputedFileName;
	CString UserInputFileName;
	CString user_input_file_name;
	afx_msg void OnBnClickedButton1();
};
