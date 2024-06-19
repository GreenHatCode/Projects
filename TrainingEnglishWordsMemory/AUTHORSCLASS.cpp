// AUTHORSCLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory_by_Zemtsov.h"
#include "AUTHORSCLASS.h"
#include "afxdialogex.h"
#include <iostream>

// AUTHORSCLASS dialog

IMPLEMENT_DYNAMIC(AUTHORSCLASS, CDialog)

AUTHORSCLASS::AUTHORSCLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_AUTHORS, pParent)
	, EC1(_T(""))
{

}

AUTHORSCLASS::~AUTHORSCLASS()
{
}

void AUTHORSCLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, EC1);
}


BEGIN_MESSAGE_MAP(AUTHORSCLASS, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &AUTHORSCLASS::OnBnClickedButton1)
END_MESSAGE_MAP()


// AUTHORSCLASS message handlers


BOOL AUTHORSCLASS::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here



	setlocale(LC_ALL, "rus");
	bool fg1 = false; // program found the start of description in settings.txt
	CString ms;

	CStdioFile SettingFile;
	SettingFile.Open(L"about.txt", CFile::modeRead);
	while (SettingFile.ReadString(CStringBuffer))	//read all strings from file settings.txt
	{
		if (CStringBuffer == "AboutAuthorsEND")fg1 = false;
		if (fg1)ms += CStringBuffer;
		if (CStringBuffer == "AboutAuthorsSTART") fg1 = true;

	}
	SettingFile.Close();

	UpdateData(true);
	EC1 = ms;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void AUTHORSCLASS::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	system("explorer https://github.com/SashaZemC.html");
}
