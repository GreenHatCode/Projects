// ABOUTAPPLICATIONCLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemoryMasterApp2.0.h"
#include "ABOUTAPPLICATIONCLASS.h"
#include "afxdialogex.h"
#include <iostream>


// ABOUTAPPLICATIONCLASS dialog

IMPLEMENT_DYNAMIC(ABOUTAPPLICATIONCLASS, CDialog)

ABOUTAPPLICATIONCLASS::ABOUTAPPLICATIONCLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ABOUTAPPLICATION, pParent)
	, EC1(_T(""))
{

}

ABOUTAPPLICATIONCLASS::~ABOUTAPPLICATIONCLASS()
{
}

void ABOUTAPPLICATIONCLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, EC1);
}


BEGIN_MESSAGE_MAP(ABOUTAPPLICATIONCLASS, CDialog)
END_MESSAGE_MAP()


// ABOUTAPPLICATIONCLASS message handlers


BOOL ABOUTAPPLICATIONCLASS::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	setlocale(LC_ALL, "rus");
	bool fg1 = false; 
	CString ms;

	CStdioFile SettingFile;
	SettingFile.Open(L"about.txt", CFile::modeRead);
	while (SettingFile.ReadString(CStringBuffer))	
	{
		if (CStringBuffer == "AboutApplicationEND")fg1 = false;
		if (fg1)ms += CStringBuffer;
		if (CStringBuffer == "AboutApplicationSTART") fg1 = true;

	}
	SettingFile.Close();

	UpdateData(true);
	EC1 = ms;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
