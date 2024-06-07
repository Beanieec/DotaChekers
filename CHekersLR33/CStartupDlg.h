#pragma once
#include "afxdialogex.h"
#include "CHekersLR33Dlg.h"


// Диалоговое окно CStartupDlg

class CStartupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStartupDlg)

public:
	CStartupDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CStartupDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STARTDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	CString strPlayerName1;
	CString strPlayerName2;
	CComboBox mTypePlayer1;
	CComboBox mTypePlayer2;
	CComboBox mFieldSkin;
	CComboBox mPlayer1Skin;
	CComboBox mPlayer2Skin;
	CCHekersLR33Dlg* dlgParent;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedApply();
	void SetDlgParent(CCHekersLR33Dlg* p);
};
