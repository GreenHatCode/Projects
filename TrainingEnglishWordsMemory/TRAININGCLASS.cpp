// TRAININGCLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory_by_Zemtsov.h"
#include "TRAININGCLASS.h"
#include "ERRORWINDOW.h"
#include "SETTINGSCLASS.h"
#include "CHANGEFILECLASS.h"
#include "afxdialogex.h"
#include <iostream>

// TRAININGCLASS dialog

IMPLEMENT_DYNAMIC(TRAININGCLASS, CDialog)

TRAININGCLASS::TRAININGCLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TRAINING, pParent)
	, TrainingType(_T("Direct"))
	, WordToTranslate(_T(""))
	, UserTranslate(_T(""))
	, SmallScreenText(_T(""))
	, BigScreenText(_T("Tap Start to begin training"))
{

}

TRAININGCLASS::~TRAININGCLASS()
{
}

void TRAININGCLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, TrainingType);
	DDX_Text(pDX, IDC_EDIT1, WordToTranslate);
	DDX_Text(pDX, IDC_EDIT2, UserTranslate);
	DDX_Text(pDX, IDC_E1, SmallScreenText);
	DDX_Text(pDX, IDC_E3, BigScreenText);
}


BEGIN_MESSAGE_MAP(TRAININGCLASS, CDialog)
	ON_COMMAND(ID_MENU_START, &TRAININGCLASS::OnMenuStart)
	ON_COMMAND(ID_MENU_STOP, &TRAININGCLASS::OnMenuStop)
	ON_COMMAND(ID_MENU_RESET, &TRAININGCLASS::OnMenuReset)
	ON_COMMAND(ID_MENU_SETTINGS, &TRAININGCLASS::OnMenuSettings)
	ON_COMMAND(ID_MENU_CHOOSEFILENAME, &TRAININGCLASS::OnMenuChooseFilename)
END_MESSAGE_MAP()


// TRAININGCLASS message handlers

BOOL TRAININGCLASS::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	setlocale(LC_ALL, "rus");


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void TRAININGCLASS::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
}

void TRAININGCLASS::OnOK()
{
	//CDialog::OnOK();
	if (FileControl)
	{
		if (StartButtonOn)
		{
			TranslateChecking();
			Word = "";

			if (fg2)WordPairCounter++;
			t = WordPairsArray[WordPairCounter];
			if (!(t == "File is empty, you know all words in it"))
			{
				CuttingWordFromStringNumber(); //uses value t

				UpdateData(true);
				WordToTranslate = Word;
				UserTranslate = "";
				UpdateData(false);
				Word.Empty();
			}
			else
			{
				if (EndlessMode)
				{
					WordPairCounter = 0;
					t = WordPairsArray[WordPairCounter];
					CuttingWordFromStringNumber();
					UpdateData(true);
					WordToTranslate = Word;
					UpdateData(false);
				}
				else
				{
					ms += "\n";
					ms += "File is empty, you know all words in it";
					UpdateData(true);
					BigScreenText = ms;
					UpdateData(false);
					FileControl = false;
				}

			}
		}
	}
}

CString TRAININGCLASS::TranslateChecking()
{
	t = WordPairsArray[WordPairCounter];// word_pair_counter begins from 1
	ms = "";
	UpdateData(true);
	Translate = UserTranslate;
	UpdateData(false);

	CuttingWordFromStringNumber();

	if (Translate == TranslateCheck)  //comparison
	{
		TranslatedWordsCounter++;
		ms = "Properly";
		if (RepeatWordWithMistake)fg2 = true;
	}
	else
	{
		IncorrectWordsCounter++;
		ms = "False, correct: ";
		ms += TranslateCheck;
		if (RepeatWordWithMistake)fg2 = false;
	}
	TranslateCheck.Empty();

	DerivationOfUserStatistics(ShowWordsAmount, ShowIncorrectWordsAmount, IncorrectWordsCounter, TranslatedWordsCounter);

	UpdateData(true);
	BigScreenText = ms;
	SmallScreenText = z;
	UpdateData(false);

	if (!fg2)
	{
		Sleep(1500);
		UpdateData(true);
		BigScreenText = "";
		UpdateData(false);
	}


	return ms;
}

CString TRAININGCLASS::CuttingWordFromStringNumber()
{
	bool fg = false;
	CString buffer1, buffer2;

	if (TrainingTypeInner) //cutting translate_check
	{
		for (int j = 0; (j < t.GetLength()); j++) // cut second word from string
		{
			if ((fg == false))Buff[0] = t.GetAt(j);
			if (fg == true)buffer1 += t[j];
			if (Buff[0] == '|')fg = true;
		}
	}
	if (!TrainingTypeInner)
	{
		for (int j = 0; (j < t.GetLength()); j++)// cut first word from string
		{
			if (fg == false)Buff[0] = t.GetAt(j);
			if (Buff[0] == '|')break;
			if (fg == false)buffer1 += t[j];

		}
	}
	TranslateCheck = buffer1;

	fg = false;
	if (TrainingTypeInner) //cutting word
	{
		for (int j = 0; (j < t.GetLength()); j++)// cut first word from string
		{
			if (fg == false)Buff[0] = t.GetAt(j);
			if (Buff[0] == '|')break;
			if (fg == false)buffer2 += t[j];
		}
	}
	if (!TrainingTypeInner)
	{
		for (int j = 0; (j < t.GetLength()); j++) // cut second word from string
		{
			if ((fg == false))Buff[0] = t.GetAt(j);
			if (fg == true)buffer2 += t[j];
			if (Buff[0] == '|')fg = true;
		}
	}
	Word = buffer2;

	return TranslateCheck, Word;
}

CString TRAININGCLASS::DerivationOfUserStatistics(bool ShowWordsAmount, bool ShowIncorrectWordsAmount, int IncorrectWordsCounter, int TranslatedWordsCounter)
{
	if ((ShowWordsAmount) && (ShowIncorrectWordsAmount)) {
		z = " mistakes: ";
		t.Format(L"%i", IncorrectWordsCounter);
		z += t;
		z += "\n";
		z += " translated words: ";
		t.Format(L"%i", TranslatedWordsCounter);
		z += t;
	}
	else if (ShowWordsAmount) {
		z = " translated words: ";
		t.Format(L"%i", TranslatedWordsCounter);
		z += t;
	}
	else if (ShowIncorrectWordsAmount) {
		z = " mistakes: ";
		t.Format(L"%i", IncorrectWordsCounter);
		z += t;
	}

	return z;
}

void TRAININGCLASS::OnMenuStart()
{
	// set up settings 

	if (!StartButtonOn)
	{
		UpdateData(true);
		h = TrainingType;
		UpdateData(false);

		if (h == "Direct")TrainingTypeInner = true; //choosing training type direct
		if (h == "Reverse")TrainingTypeInner = false; //choosing training type reverse

		///////////////////// set up settings from SETTINGS menu
		CStdioFile setting_file;

		if (setting_file.Open(L"settings.txt", CFile::modeRead))
		{
			while (setting_file.ReadString(Buffer1))	//read all strings from file settings.txt
			{
				SettingsArray.Add(Buffer1);
			}
			setting_file.Close();

			//set training settings from setting menu
			h = SettingsArray[0]; // example of string: 0 1 0 0 1
			if (h[0] == '0')ShowIncorrectWordsAmount = false; //the first digit
			else ShowIncorrectWordsAmount = true;

			if (h[2] == '0')ShowWordsAmount = false;
			else ShowWordsAmount = true;

			if (h[4] == '0')EndlessMode = false;
			else EndlessMode = true;

			if (h[6] == '0')RepeatWordWithMistake = false; //the last digit
			else RepeatWordWithMistake = true;
		}
		else
		{
			ERRORWINDOW ErrorTablet;
			ErrorTablet.ReadErrorType(2);
			ErrorTablet.DoModal();
		}

		//read information from user file 
		h = SettingsArray[1];
		CStdioFile ResourceFile;
		if (ResourceFile.Open(h, CFile::modeRead))
		{
			while (ResourceFile.ReadString(Buffer1))
			{
				WordPairsArray.Add(Buffer1);
			}
			ResourceFile.Close();
		}
		else
		{
			ERRORWINDOW ErrorTablet;
			ErrorTablet.ReadErrorType(2);
			ErrorTablet.DoModal();
		}
		/////////////////////////
		TranslatedWordsCounter = 0;
		IncorrectWordsCounter = 0;

		ShowWordsAmount = true;
		ShowIncorrectWordsAmount = true;

		t = WordPairsArray[WordPairCounter];
		CuttingWordFromStringNumber();

		DerivationOfUserStatistics(ShowWordsAmount, ShowIncorrectWordsAmount, IncorrectWordsCounter, TranslatedWordsCounter);

		UpdateData(true);
		WordToTranslate = Word;
		h = TrainingType;
		SmallScreenText = z;
		UpdateData(false);

		StartButtonOn = true;
	}

}

void TRAININGCLASS::OnMenuStop()
{
	if (StartButtonOn)StartButtonOn = false;
	else if (!StartButtonOn)StartButtonOn = true;
}

void TRAININGCLASS::OnMenuReset()
{
	// TODO: Add your command handler code here
	WordPairCounter = 0;
	StartButtonOn = false;
	FileControl = true;
	SettingsArray.RemoveAll();
	z = "";

	UpdateData(true);
	SmallScreenText = z;
	WordToTranslate = "";
	BigScreenText = "";
	UserTranslate = "";
	UpdateData(false);
}

void TRAININGCLASS::OnMenuSettings()
{
	SETTINGSCLASS newTablet;
	newTablet.DoModal();
}

void TRAININGCLASS::OnMenuChooseFilename()
{
	// TODO: Add your command handler code here

	CHANGEFILECLASS newTablet;
	newTablet.DoModal();

}
