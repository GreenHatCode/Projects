// SETTINGSCLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory_by_Zemtsov.h"
#include "SETTINGSCLASS.h"
#include "afxdialogex.h"


// SETTINGSCLASS dialog

IMPLEMENT_DYNAMIC(SETTINGSCLASS, CDialog)

SETTINGSCLASS::SETTINGSCLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETTINGS, pParent)
	, ShowIncorrectWordsAmount(FALSE)
	, ShowTranslatedWordsAmount(FALSE)
	, EndlessMode(FALSE)
	, RepeatWordWithMistake(FALSE)
{

}

SETTINGSCLASS::~SETTINGSCLASS()
{
}

void SETTINGSCLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, ShowIncorrectWordsAmount);
	DDX_Check(pDX, IDC_CHECK2, ShowTranslatedWordsAmount);
	DDX_Check(pDX, IDC_CHECK3, EndlessMode);
	DDX_Check(pDX, IDC_CHECK4, RepeatWordWithMistake);
}


BEGIN_MESSAGE_MAP(SETTINGSCLASS, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &SETTINGSCLASS::OnBnClickedButton1)
END_MESSAGE_MAP()


// SETTINGSCLASS message handlers


void SETTINGSCLASS::OnBnClickedButton1()
{
	CStdioFile setting_file(L"settings.txt", CFile::modeWrite);

	UpdateData(true);
	ShowIncorrectWordsAmountInner = ShowIncorrectWordsAmount;
	ShowTranslatedWordsAmountInner = ShowTranslatedWordsAmount;
	EndlessModeInner = EndlessMode;
	RepeatWordWithMistakeInner = RepeatWordWithMistake;
	UpdateData(false);

	t.Format(L"%i", (int)ShowIncorrectWordsAmountInner);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)ShowTranslatedWordsAmountInner);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)EndlessModeInner);
	ms += t;
	ms += " ";
	t.Format(L"%i", (int)RepeatWordWithMistakeInner);
	ms += t;

	setting_file.WriteString(ms);
	setting_file.Flush();
	setting_file.Close();


}
