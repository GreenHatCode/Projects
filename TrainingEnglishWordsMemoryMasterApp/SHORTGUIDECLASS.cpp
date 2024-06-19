// SHORTGUIDECLASS.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemoryMasterApp2.0.h"
#include "SHORTGUIDECLASS.h"
#include "afxdialogex.h"


// SHORTGUIDECLASS dialog

IMPLEMENT_DYNAMIC(SHORTGUIDECLASS, CDialog)

SHORTGUIDECLASS::SHORTGUIDECLASS(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SHORTGUIDE, pParent)
{

}

SHORTGUIDECLASS::~SHORTGUIDECLASS()
{
}

void SHORTGUIDECLASS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, E1);
}


BEGIN_MESSAGE_MAP(SHORTGUIDECLASS, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &SHORTGUIDECLASS::OnBnClickedButton1)
END_MESSAGE_MAP()


// SHORTGUIDECLASS message handlers


void SHORTGUIDECLASS::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	if ((n == 1)) {
		E1.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1)));
		n++;
	}
	else if ((n == 2)) {
		E1.SetBitmap(::LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP2)));
		n=1;
	}

}
