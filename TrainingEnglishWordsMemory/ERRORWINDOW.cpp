// ERRORWINDOW.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory_by_Zemtsov.h"
#include "ERRORWINDOW.h"
#include "afxdialogex.h"


// ERRORWINDOW dialog

IMPLEMENT_DYNAMIC(ERRORWINDOW, CDialog)

ERRORWINDOW::ERRORWINDOW(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ERRORWINDOW, pParent)
	, E2(_T(""))
{

}

ERRORWINDOW::~ERRORWINDOW()
{
}

void ERRORWINDOW::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E2, E2);
}

BOOL ERRORWINDOW::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	UpdateData(true);
	E2 = messageE2;
	UpdateData(false);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

CString ERRORWINDOW::ReadErrorType(int x)
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
			if (fg1 && CStringBuffer[0]==number)messageE2 += CStringBuffer; 
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
	messageE2 = "	";
	messageE2 += CStringBuffer;

	return messageE2;
}


BEGIN_MESSAGE_MAP(ERRORWINDOW, CDialog)
END_MESSAGE_MAP()


// ERRORWINDOW message handlers



