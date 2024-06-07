// CStartupDlg.cpp: файл реализации
//

#include "pch.h"
#include "CHekersLR33.h"
#include "afxdialogex.h"
#include "CStartupDlg.h"


// Диалоговое окно CStartupDlg

IMPLEMENT_DYNAMIC(CStartupDlg, CDialogEx)

CStartupDlg::CStartupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STARTDIALOG, pParent)
	, strPlayerName1(_T(""))
	, strPlayerName2(_T(""))
{

}

CStartupDlg::~CStartupDlg()
{
}

void CStartupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITNAMEPLAYER1, strPlayerName1);
	DDX_Text(pDX, IDC_EDITNAMEPLAYER2, strPlayerName2);
	DDX_Control(pDX, IDC_COMBO1, mTypePlayer1);
	DDX_Control(pDX, IDC_COMBO2, mTypePlayer2);
	DDX_Control(pDX, IDC_FIELDSKIN, mFieldSkin);
	DDX_Control(pDX, IDC_PLAYER1SKIN, mPlayer1Skin);
	DDX_Control(pDX, IDC_PLAYER2SKIN, mPlayer2Skin);
}


BEGIN_MESSAGE_MAP(CStartupDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(ID_APPLY, &CStartupDlg::OnBnClickedApply)
END_MESSAGE_MAP()

// Обработчики сообщений CStartupDlg

BOOL CStartupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	mTypePlayer1.SetCurSel(0);
	mTypePlayer2.SetCurSel(0);
	mFieldSkin.SetCurSel(0);
	mPlayer1Skin.SetCurSel(0);
	mPlayer2Skin.SetCurSel(0);
	return TRUE;
}

void CStartupDlg::OnBnClickedApply()
{
	UpdateData(TRUE);
	if ((strPlayerName1 == L"") || (strPlayerName2 == L""))
	{
		AfxMessageBox(L"Укажите имя игроков");
			return;
	}
	dlgParent->CreateBoard(8);
	dlgParent->CreatePlayer1(strPlayerName1, mTypePlayer1.GetCurSel());
	dlgParent->CreatePlayer2(strPlayerName2, mTypePlayer2.GetCurSel());
	dlgParent->GetDlgItem(IDC_BUTTONSTART)->EnableWindow(TRUE);
	this->EndDialog(IDOK);
}

void CStartupDlg::SetDlgParent(CCHekersLR33Dlg* p) {
	this->dlgParent = p;
}
