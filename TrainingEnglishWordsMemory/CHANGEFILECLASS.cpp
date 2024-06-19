// CHANGEFILECLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory_by_Zemtsov.h"
#include "CHANGEFILECLASS.h"
#include "afxdialogex.h"


// CHANGEFILECLASS dialog

IMPLEMENT_DYNAMIC(CHANGEFILECLASS, CDialog)

CHANGEFILECLASS::CHANGEFILECLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHANGEFILE, pParent)
	, FileName(_T(""))
{

}

CHANGEFILECLASS::~CHANGEFILECLASS()
{
}

void CHANGEFILECLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FileName);
}


BEGIN_MESSAGE_MAP(CHANGEFILECLASS, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CHANGEFILECLASS::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHANGEFILECLASS message handlers


void CHANGEFILECLASS::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString ms;
	CString All_Lines;
	CStringArray settingsArray;

	UpdateData(true);
	InputedFileName = FileName;
	UpdateData(false);

	CStdioFile SettingFile(L"settings.txt", CFile::modeRead);
	while (SettingFile.ReadString(All_Lines))
	{
		settingsArray.Add(All_Lines);
	}
	SettingFile.Close();

	ms = InputedFileName;
	if (!((InputedFileName[InputedFileName.GetLength() - 1] == 't') && (InputedFileName[InputedFileName.GetLength() - 2] == 'x') &&
		(InputedFileName[InputedFileName.GetLength() - 3] == 't') && (InputedFileName[InputedFileName.GetLength() - 4] == '.')))ms += ".txt";

	settingsArray[1] = ms;
	ms = settingsArray[0];
	for (int i = 1; i < settingsArray.GetSize(); i++)
	{
		ms += "\n";
		ms += settingsArray[i];
	}

	CStdioFile write_setting_in_file(L"recreate.txt", CFile::modeCreate | CFile::modeWrite);
	write_setting_in_file.WriteString(ms);
	write_setting_in_file.Flush();
	write_setting_in_file.Close();
	remove("settings.txt");
	rename("recreate.txt", "settings.txt");



}
