
// CHekersLR33Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "CHekersLR33.h"
#include "CHekersLR33Dlg.h"
#include "afxdialogex.h"
#include "CStartupDlg.h"
#include "HumPlayer.h"
#include "RandPlayer.h"
#include "BotPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CCHekersLR33Dlg



CCHekersLR33Dlg::CCHekersLR33Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHEKERSLR33_DIALOG, pParent)
	, strPlayerTurn(_T(""))
{
	board = nullptr;
	player1 = nullptr;
	player2 = nullptr;
	currentPlayer = nullptr;


	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCHekersLR33Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FIELD, tttField);
	/*DDX_Control(pDX, IDC_BUTTONSTART, mStartButton);*/
	DDX_Text(pDX, IDC_NOWPLAYER, strPlayerTurn);
}

BEGIN_MESSAGE_MAP(CCHekersLR33Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BUTTONSTART, &CCHekersLR33Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTONSETTINGS, &CCHekersLR33Dlg::OnBnClickedButtonSettings)
	ON_WM_DRAWITEM()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTONSETTINGS2, &CCHekersLR33Dlg::OnBnClickedButtonsettings2)
END_MESSAGE_MAP()


// Обработчики сообщений CCHekersLR33Dlg

BOOL CCHekersLR33Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	tttField.SetGameParent(this);
	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCHekersLR33Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCHekersLR33Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CCHekersLR33Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	SetDCBrushColor(*pDC, RGB(23, 20, 20));
	return (HBRUSH)GetStockObject(DC_BRUSH);
}


void CCHekersLR33Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	switch (nChar)
	{
	case VK_SPACE:
		EndDialog(IDOK);
		break;
	default:
		break;
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CCHekersLR33Dlg::OnBnClickedButtonStart()
{
	if (bGameInProgress) {
		this->board->ClearBoard();
		countclick = 0;
		this->GetDlgItem(IDC_BUTTONSTART)->EnableWindow(FALSE);
		this->GetDlgItem(IDC_BUTTONSETTINGS)->EnableWindow(TRUE);
		this->SetGameInProgress(false);
		strPlayerTurn = L"";
		UpdateData(FALSE);
		this->Invalidate();
		CString str;
		str.Format(L"Игрок %s сдался", currentPlayer->GetName());
		AfxMessageBox(str);

	}
	else if (!bGameInProgress && countclick != 0) {
		this->board->ClearBoard();
		countclick = 0;
		this->GetDlgItem(IDC_BUTTONSTART)->EnableWindow(FALSE);
		this->GetDlgItem(IDC_BUTTONSETTINGS)->EnableWindow(TRUE);
		this->SetGameInProgress(false);
		strPlayerTurn = L"";
		UpdateData(FALSE);
		this->Invalidate();
	}
	else
	{	
		countclick++;
		this->GetDlgItem(IDC_BUTTONSETTINGS)->EnableWindow(FALSE);
		this->SetGameInProgress(true);
		tttField.StartPositions();
		currentPlayer = player1;
		this->UpdateName();
		CWnd* rule = GetDlgItem(IDC_BUTTONSETTINGS2);
		if (rule) {
			rule->DestroyWindow();
		}
		UpdateData(FALSE);

		
	}
}

void CCHekersLR33Dlg::UpdateName() {
	CString str;
	str.Format(L"Ход игрока: %s", currentPlayer->GetName());
	strPlayerTurn = str;
	CFont newFont;
	newFont.CreatePointFont(220, _T("Satyr SP"));
	CWnd* text = GetDlgItem(IDC_NOWPLAYER);
	text->SetFont(&newFont);
	text->SetWindowText(strPlayerTurn);
}

void CCHekersLR33Dlg::OnBnClickedButtonSettings()
{
	CStartupDlg sdlg;
	sdlg.SetDlgParent(this);
	int nRes = sdlg.DoModal();
	if (nRes == IDOK) {

	}
}

ChekersBoard* CCHekersLR33Dlg::GetBoard() {
	return board;
}

Player* CCHekersLR33Dlg::GetCurrentPlayer() {
	return currentPlayer;
}

void CCHekersLR33Dlg::CreateBoard(int size) {
	this->board = new ChekersBoard(size);
}

void CCHekersLR33Dlg::CreatePlayer1(CString name, int type) {
	switch (type)
	{
	case 0:
		this->player1 = new HumPlayer;
		break;
	case 1:
		this->player1 = new BotPlayer;
		break;
	case 2:
		this->player1 = new RandPlayer;
		break;
	default:
		this->player1 = new HumPlayer;
		break;
	}
	player1->SetupPlayer(name, CELLTYPE_PWHITE, CELLTYPE_EBLACK, CELLTYPE_WOMWHITE);
	player1->SetBoard(this->board);
}

void CCHekersLR33Dlg::CreatePlayer2(CString name, int type) {
	switch (type)
	{
	case 0:
		this->player2 = new HumPlayer;
		break;
	case 1:
		this->player2 = new BotPlayer;
		break;
	case 2:
		this->player2 = new RandPlayer;
		break;
	default:
		this->player2 = new HumPlayer;
		break;
	}
	player2->SetupPlayer(name, CELLTYPE_PBLACK, CELLTYPE_EBLACK, CELLTYPE_WOMBLACK);
	player2->SetBoard(this->board);
}

void CCHekersLR33Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rect = lpDrawItemStruct->rcItem;
	CFont font;
	font.CreatePointFont(200, L"Satyr SP");
	dc.FillSolidRect(&rect, RGB(110, 18, 15));
	dc.SelectObject(font);
	dc.SetTextColor(RGB(255, 255, 224));
	if (nIDCtl == IDC_BUTTONSTART) {
		if (countclick == 0) {
			CString buttonText = (L"Играть");
			dc.DrawText(buttonText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else {
			CString buttonText = (L"Стоп");
			dc.DrawText(buttonText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
	}
	if (nIDCtl == IDC_BUTTONSETTINGS) {
		CString buttonText = (L"Настройки");
		dc.DrawText(buttonText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (nIDCtl == IDC_BUTTONSETTINGS2) {
		CString buttonText = (L"Правила");
		dc.DrawText(buttonText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	dc.Detach();
	font.DeleteObject();
	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CCHekersLR33Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}

void CCHekersLR33Dlg::SetGameInProgress(bool inProgress) {
	this->bGameInProgress = inProgress;
	this->tttField.SetGameInProgress(inProgress);
	if (inProgress) {
		countclick = 1;
	}
}

void CCHekersLR33Dlg::TogglePlayer() {
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
	UpdateName();
}

void CCHekersLR33Dlg::OnBnClickedButtonsettings2()
{
	AfxMessageBox(L"1.Обычные шашки ходят и едят только вперёд и на одно поле.                                                                                        2.При достижении крайнего поля, относительно своей стороны, обычная шашка превращается в дамку.                   3.Дамки могут ходить и есть назад, но в отличии от Русских шашек, только на 1 поле.                                                          4.Если у игрока появляется возможность съесть вражескую шашку, то он обязан её съесть, сделать другой ход не получится.                                                                              5.Когда у одного из игроков заканчиваются шашки, другой игрок побеждает, и игра заканчивается.");
}
