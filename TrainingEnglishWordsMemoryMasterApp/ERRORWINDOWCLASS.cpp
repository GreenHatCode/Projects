// ERRORWINDOWCLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemoryMasterApp2.0.h"
#include "ERRORWINDOWCLASS.h"
#include "afxdialogex.h"


// ERRORWINDOWCLASS dialog

IMPLEMENT_DYNAMIC(ERRORWINDOWCLASS, CDialog)

ERRORWINDOWCLASS::ERRORWINDOWCLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ERRORWINDOW, pParent)
	, E2(_T(""))
{

}

ERRORWINDOWCLASS::~ERRORWINDOWCLASS()
{
}

void ERRORWINDOWCLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E2, E2);
}

BEGIN_MESSAGE_MAP(ERRORWINDOWCLASS, CDialog)
END_MESSAGE_MAP()

// ERRORWINDOWCLASS message handlers
BOOL ERRORWINDOWCLASS::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	UpdateData(true);
	E2 = messageE2;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

CString ERRORWINDOWCLASS::ReadErrorType(int x)
{
	ErrorType = x;
	char number; // char form of ErroType

	switch (x)
	{
	case 1:
		number = '1';
		break;
	case 2:
		number = '2';
		break;
	case 3:
		number = '3';
		break;
	}

	CStdioFile SettingFile;
	if (SettingFile.Open(L"errorlist.txt", CFile::modeRead))
	{
		while (SettingFile.ReadString(CStringBuffer))	//read all strings from file settings.txt
		{
			if (CStringBuffer == "ErrorTextEND")fg1 = false;
			if (fg1 && CStringBuffer[0] == number)messageE2 += CStringBuffer;
			if (CStringBuffer == "ErrorTextSTART") fg1 = true;

		}
		SettingFile.Close();
	}
	else
	{
		messageE2 = "3errorlist.txt is missed, it is recommended to reinstall the application";
	}

	messageE2.SetAt(0, ' ');
	CStringBuffer = messageE2;
	messageE2 = "";
	messageE2 += CStringBuffer;

	return messageE2;
}