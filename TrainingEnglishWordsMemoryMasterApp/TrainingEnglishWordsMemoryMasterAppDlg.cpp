
// TrainingEnglishWordsMemoryMasterApp2.0Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TrainingEnglishWordsMemoryMasterApp2.0.h"
#include "TrainingEnglishWordsMemoryMasterApp2.0Dlg.h"
#include "afxdialogex.h"
#include "SHORTGUIDECLASS.h"
#include "ABOUTAPPLICATIONCLASS.h"
#include "ERRORWINDOWCLASS.h"
#include "AUTHORSCLASS.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrainingEnglishWordsMemoryMasterApp20Dlg dialog



CTrainingEnglishWordsMemoryMasterApp20Dlg::CTrainingEnglishWordsMemoryMasterApp20Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TRAININGENGLISHWORDSMEMORYMASTERAPP20_DIALOG, pParent)
	, InputFilename(_T(""))
	, Text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrainingEnglishWordsMemoryMasterApp20Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, InputFilename);
	DDX_Text(pDX, IDC_EDIT2, Text);
}

BEGIN_MESSAGE_MAP(CTrainingEnglishWordsMemoryMasterApp20Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABOUT_SHORTGUIDE, &CTrainingEnglishWordsMemoryMasterApp20Dlg::OnAboutShortguide)
	ON_COMMAND(ID_ABOUT_ABOUTAPPLICATION, &CTrainingEnglishWordsMemoryMasterApp20Dlg::OnAboutAboutapplication)
	ON_COMMAND(ID_ABOUT_AUTHORS, &CTrainingEnglishWordsMemoryMasterApp20Dlg::OnAboutAuthors)
	ON_COMMAND(ID_FILE_OPEN32775, &CTrainingEnglishWordsMemoryMasterApp20Dlg::OnFileOpen32775)
	ON_COMMAND(ID_FILE_CLOSE32776, &CTrainingEnglishWordsMemoryMasterApp20Dlg::OnFileClose32776)
	ON_COMMAND(ID_SAVECHANGES, &CTrainingEnglishWordsMemoryMasterApp20Dlg::OnSavechanges)
END_MESSAGE_MAP()


// CTrainingEnglishWordsMemoryMasterApp20Dlg message handlers

BOOL CTrainingEnglishWordsMemoryMasterApp20Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	setlocale(LC_ALL, "rus");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrainingEnglishWordsMemoryMasterApp20Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnAboutShortguide()
{
	// TODO: Add your command handler code here
	SHORTGUIDECLASS newTablet;
	newTablet.DoModal();
}


void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnAboutAboutapplication()
{
	// TODO: Add your command handler code here
	CStdioFile TestObject;
	if (TestObject.Open(L"about.txt", CFile::modeRead))
	{
		TestObject.Close();
		ABOUTAPPLICATIONCLASS newTablet;
		newTablet.DoModal();
	}
	else
	{
		ERRORWINDOWCLASS ErrorTablet;
		ErrorTablet.ReadErrorType(3);
		ErrorTablet.DoModal();
	}
}


void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnAboutAuthors()
{
	// TODO: Add your command handler code here

	CStdioFile TestObject;
	if (TestObject.Open(L"about.txt", CFile::modeRead))
	{
		TestObject.Close();
		AUTHORSCLASS newTablet;
		newTablet.DoModal();
	}
	else
	{
		ERRORWINDOWCLASS ErrorTablet;
		ErrorTablet.ReadErrorType(3);
		ErrorTablet.DoModal();
	}

}


void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnFileOpen32775()
{
	// TODO: Add your command handler code here

	UpdateData(true);
	UserFilename = InputFilename;
	UpdateData(false);
	if (UserFilename.IsEmpty())
	{
		UpdateData(true);
		InputFilename = "Enter a file name please";
		UpdateData(false);
		InputFilename.Empty();
	}
	else
	{
		if (!((UserFilename[UserFilename.GetLength() - 1] == 't') && (UserFilename[UserFilename.GetLength() - 2] == 'x') &&
			(UserFilename[UserFilename.GetLength() - 3] == 't') && (UserFilename[UserFilename.GetLength() - 4] == '.')))UserFilename += ".txt";

		CStdioFile SourceFile;

		if (SourceFile.Open(UserFilename, CFile::modeRead))
		{
			while (SourceFile.ReadString(Buffer1))	//read all strings from file data.txt
			{
				if (Buffer1 != "File is empty, you know all words in it")
				{
					for (int k = 0; k < Buffer1.GetLength(); k++)
					{
						if (Buffer1[k] == '|')Buffer1.SetAt(k, ' ');
					}
					Buffer1 += "\r\n";
					Buffer2 += Buffer1;
				}
			}
			SourceFile.Close();

			UpdateData(true);
			Text = Buffer2;
			UpdateData(false);
		}
		else
		{
			UpdateData(true);
			InputFilename = "This file is absent in app directory";
			UpdateData(false);
		}


	}

}


void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnFileClose32776()
{
	// TODO: Add your command handler code here

	Buffer2.Empty();
	UserFilename.Empty();
	Buffer1.Empty();
	Buffer2.Empty();
	CstringBufferName.Empty();

	UpdateData(true);
	Text = Buffer2;
	InputFilename = UserFilename;
	UpdateData(false);

}


void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnSavechanges()
{
	// TODO: Add your command handler code here

	UpdateData(true);
	Buffer2 = Text;
	UserFilename = InputFilename;
	UpdateData(false);

	if (!Buffer2.IsEmpty())
	{
		for (int i = 0; i < Buffer2.GetLength(); i++)
		{
			if (Buffer2[i] == '\r')Buffer2.Delete(i, 1);
			if (Buffer2[i] == '³')Buffer2.SetAt(i, 'i');
			if (Buffer2[i] == '²')Buffer2.SetAt(i, 'I');
		}

		if (Buffer2[Buffer2.GetLength() - 1] == '\n')Buffer2 += "File is empty, you know all words in it";
		else if (Buffer2[Buffer2.GetLength() - 1] != '\n')Buffer2 += "\nFile is empty, you know all words in it";
	
		if (UserFilename.IsEmpty())
		{
			UpdateData(true);
			InputFilename = "Enter a file name please";
			UpdateData(false);
			InputFilename.Empty();
		}
		else
		{
			if (!((UserFilename[UserFilename.GetLength() - 1] == 't') && (UserFilename[UserFilename.GetLength() - 2] == 'x') &&
				(UserFilename[UserFilename.GetLength() - 3] == 't') && (UserFilename[UserFilename.GetLength() - 4] == '.')))UserFilename += ".txt";
			WriteOutputInFile(UserFilename);
		}
	}
	else
	{
		UpdateData(true);
		Text = "You can't save empty file. Write here something.";
		UpdateData(false);
	}


}

CString CTrainingEnglishWordsMemoryMasterApp20Dlg::ReplacingSpaceInString(CString CString_Buffer1)
{
	for (int i = 0; i < CString_Buffer1.GetLength(); i++)
	{
		if (CString_Buffer1[i + 1] == char(32))
		{
			fg1 = false;
			fg2 = false;
			for (int k = 97; k < 123; k++)
			{
				if (CString_Buffer1[i] == char(k))fg1 = true;
			}
			for (int k = 97; k < 123; k++)
			{
				if (CString_Buffer1[i + 2] == char(k))fg2 = true;
			}
			if (fg1 && !fg2)CString_Buffer1.SetAt(i + 1, '|');
		}

	}
	Buffer2 = CString_Buffer1;

	return CString();
}

void CTrainingEnglishWordsMemoryMasterApp20Dlg::WriteOutputInFile(CString User_input_file_name)
{
	char CharUserFilename[256];
	strcpy_s(CharUserFilename, CStringA(User_input_file_name).GetString());

	Buffer1 = Buffer2;
	ReplacingSpaceInString(Buffer1);
	CstringBufferName = "text.txt";
	CStdioFile File;
	File.Open(CstringBufferName, CFile::modeCreate | CFile::modeWrite);
	File.WriteString(Buffer2);
	File.Flush();
	File.Close();
	remove(CharUserFilename); 
	rename("text.txt", CharUserFilename);
}

void CTrainingEnglishWordsMemoryMasterApp20Dlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnOK();
}
