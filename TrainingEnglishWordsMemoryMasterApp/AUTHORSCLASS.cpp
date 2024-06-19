// AUTHORSCLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemoryMasterApp2.0.h"
#include "AUTHORSCLASS.h"
#include "afxdialogex.h"
#include <iostream>


// AUTHORSCLASS dialog

IMPLEMENT_DYNAMIC(AUTHORSCLASS, CDialog)

AUTHORSCLASS::AUTHORSCLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_AUTHORS, pParent)
	, E2(_T(""))
{

}

AUTHORSCLASS::~AUTHORSCLASS()
{
}

void AUTHORSCLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, E2);
}


BEGIN_MESSAGE_MAP(AUTHORSCLASS, CDialog)
END_MESSAGE_MAP()


// AUTHORSCLASS message handlers


BOOL AUTHORSCLASS::OnInitDialog()
{
	CDialog::OnInitDialog();

	setlocale(LC_ALL, "rus");
	bool fg1 = false; 
	CString ms;

	CStdioFile SettingFile;
	SettingFile.Open(L"about.txt", CFile::modeRead);
	while (SettingFile.ReadString(CStringBuffer))
	{
		if (CStringBuffer == "AboutAuthorsEND")fg1 = false;
		if (fg1)ms += CStringBuffer;
		if (CStringBuffer == "AboutAuthorsSTART") fg1 = true;

	}
	SettingFile.Close();

	UpdateData(true);
	E2 = ms;
	UpdateData(false);

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
