#pragma once


// TRAININGCLASS dialog

class TRAININGCLASS : public CDialog
{
	DECLARE_DYNAMIC(TRAININGCLASS)

public:
	TRAININGCLASS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TRAININGCLASS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAINING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString TrainingType;//combobox
	CString WordToTranslate;//left editcontrol
	CString UserTranslate;//right editcontrol
	CString SmallScreenText;
	CString BigScreenText;

	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	afx_msg CString TRAININGCLASS::TranslateChecking();
	afx_msg CString TRAININGCLASS::CuttingWordFromStringNumber();
	afx_msg CString TRAININGCLASS::DerivationOfUserStatistics(bool ShowWordsAmount, bool ShowIncorrectWordsAmount, int IncorrectWordsCounter, int TranslatedWordsCounter);

	CString Buffer1, Buffer2, Buffer3;
	CStringArray WordPairsArray;
	CStringArray SettingsArray;
	CString ms, t, z, h;
	CString Word, Translate, TranslateCheck;

	int WordPairCounter = 0;
	int ArrayOfWordsWithMistakes[20];
	char Buff[20];
	bool FileControl = true, StartButtonOn = false;
	bool TrainingTypeInner;
	char ch;
	int IncorrectWordsCounter;
	int TranslatedWordsCounter;
	bool ShowWordsAmount;
	bool ShowIncorrectWordsAmount;
	bool EndlessMode;
	bool RepeatWordWithMistake;
	bool fg2 = true;
	bool fg1 = true;
	int BufferCounter, a;



public:
	afx_msg void OnMenuStart();
	afx_msg void OnMenuStop();
	afx_msg void OnMenuReset();
	afx_msg void OnMenuSettings();
	afx_msg void OnMenuChooseFilename();
};
