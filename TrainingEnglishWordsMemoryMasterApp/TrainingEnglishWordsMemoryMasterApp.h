
// TrainingEnglishWordsMemoryMasterApp2.0.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTrainingEnglishWordsMemoryMasterApp20App:
// See TrainingEnglishWordsMemoryMasterApp2.0.cpp for the implementation of this class
//

class CTrainingEnglishWordsMemoryMasterApp20App : public CWinApp
{
public:
	CTrainingEnglishWordsMemoryMasterApp20App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTrainingEnglishWordsMemoryMasterApp20App theApp;
