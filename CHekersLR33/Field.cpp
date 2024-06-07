// Field.cpp: файл реализации
//
#pragma once
#include "pch.h"
#include "CHekersLR33.h"
#include "Field.h"

#define FIELD_CLASSNAME L"Field"
#define CORRECTNUM 40
#define TIMER_ID 101
#define PI 3.14

// Field

IMPLEMENT_DYNAMIC(Field, CWnd)

Field::Field()
{
	gameParent = nullptr;
	this->RegisterClass();
	SelectX = -1;
	SelectY = -1;
	SelectedX = -20;
	SelectedY = -20;
}

Field::~Field()
{
}

BEGIN_MESSAGE_MAP(Field, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
ON_WM_MOUSEMOVE()
ON_WM_MOUSELEAVE()
ON_WM_RBUTTONUP()
ON_WM_TIMER()
END_MESSAGE_MAP()

void Field::SetGameParent(CCHekersLR33Dlg* p) {
	this->gameParent = p;
}

void Field::DrawPers(int kind, CDC& pDC, CRect rect){

	HBITMAP rSimp = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_radiSimp), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADTRANSPARENT);
	HBITMAP rWom = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_radiWom), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADTRANSPARENT);
	HBITMAP dSimp = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_direSimp), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADTRANSPARENT);
	HBITMAP dWom = (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_direWom), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADTRANSPARENT);
	switch (kind)
	{
	case 1:
		if (rSimp != NULL) {
			BITMAP bmp;
			GetObject(rSimp, sizeof(BITMAP), &bmp);

			CDC cdc;
			cdc.CreateCompatibleDC(&pDC);
			SelectObject(cdc, rSimp);

			COLORREF colorTransparent = GetPixel(cdc, 0, 0);
			
			pDC.TransparentBlt(rect.left - 15, rect.top - 27, bmp.bmWidth, bmp.bmHeight, &cdc, 0, 0, bmp.bmWidth, bmp.bmHeight, colorTransparent);
			
		}
		break;
	case 2:
		if (rWom != NULL) {
			BITMAP bmp;
			GetObject(rWom, sizeof(BITMAP), &bmp);

			CDC cdc;
			cdc.CreateCompatibleDC(&pDC);
			SelectObject(cdc, rWom);

			COLORREF colorTransparent = GetPixel(cdc, 0, 0);

			pDC.TransparentBlt(rect.left - 35, rect.top - 37, bmp.bmWidth, bmp.bmHeight, &cdc, 0, 0, bmp.bmWidth, bmp.bmHeight, colorTransparent);
			
			DeleteObject(rWom);
		}
		break;
	case 3:
		if (dSimp != NULL) {
			BITMAP bmp;
			GetObject(dSimp, sizeof(BITMAP), &bmp);

			CDC cdc;
			cdc.CreateCompatibleDC(&pDC);
			SelectObject(cdc, dSimp);

			COLORREF colorTransparent = GetPixel(cdc, 0, 0);

			pDC.TransparentBlt(rect.left - 30, rect.top - 27, bmp.bmWidth, bmp.bmHeight, &cdc, 0, 0, bmp.bmWidth, bmp.bmHeight, colorTransparent);
			
			DeleteObject(dSimp);
		}
		break;
	case 4:
		if (dWom != NULL) {
			BITMAP bmp;
			GetObject(dWom, sizeof(BITMAP), &bmp);

			CDC cdc;
			cdc.CreateCompatibleDC(&pDC);
			SelectObject(cdc, dWom);

			COLORREF colorTransparent = GetPixel(cdc, 0, 0);

			pDC.TransparentBlt(rect.left - 25, rect.top - 25, bmp.bmWidth, bmp.bmHeight, &cdc, 0, 0, bmp.bmWidth, bmp.bmHeight, colorTransparent);
			
			DeleteObject(dWom);
		}
		break;
	default:
		break;
	}
	DeleteObject(rSimp);
	DeleteObject(rWom);
	DeleteObject(dSimp);
	DeleteObject(dWom);
}

 void Field::DrawIcons(CDC* pDC) {
	 int corctXX = 3;
	 int corctYY = -5;
	 float multip = 1.5;
	 CPoint points[4];
	 points[0] = CPoint(93 * multip + corctXX, 253 * multip + corctYY);
	 points[1] = CPoint(163 * multip + corctXX, 322 * multip + corctYY);
	 points[2] = CPoint(111 * multip + corctXX, 340 * multip + corctYY);
	 points[3] = CPoint(69 * multip + corctXX, 312 * multip + corctYY);
	 pDC->Polygon(points, 4);

	 CPoint points1[5];
	 points1[0] = CPoint(95 * multip + corctXX, 90 * multip + corctYY);
	 points1[1] = CPoint(353 * multip + corctXX, 265 * multip + corctYY);
	 points1[2] = CPoint(327 * multip + corctXX, 336 * multip + corctYY);
	 points1[3] = CPoint(281 * multip + corctXX, 330 * multip + corctYY);
	 points1[4] = CPoint(68 * multip + corctXX, 98 * multip + corctYY);
	 pDC->Polygon(points1, 5);

	 CPoint points2[4];
	 points2[0] = CPoint(250 * multip + corctXX, 107 * multip + corctYY);
	 points2[1] = CPoint(302 * multip + corctXX, 93 * multip + corctYY);
	 points2[2] = CPoint(324 * multip + corctXX, 112 * multip + corctYY);
	 points2[3] = CPoint(314 * multip + corctXX, 159 * multip + corctYY);
	 pDC->Polygon(points2, 4);
}
 
 void Field::DrawCant(CDC* pDC) {
	 int corectX = 0;
	 int corectY = 0;
	 float multip = 1.5;
	 CPoint points3[45];
	 points3[0] = CPoint(9 * multip + corectX, 8 * multip + corectY);
	 points3[1] = CPoint(22 * multip + corectX, 9 * multip + corectY);
	 points3[2] = CPoint(32 * multip + corectX, 6 * multip + corectY);
	 points3[3] = CPoint(95 * multip + corectX, 10 * multip + corectY);
	 points3[4] = CPoint(111 * multip + corectX, 6 * multip + corectY);
	 points3[5] = CPoint(130 * multip + corectX, 13 * multip + corectY);
	 points3[6] = CPoint(152 * multip + corectX, 14 * multip + corectY);
	 points3[7] = CPoint(167 * multip + corectX, 2 * multip + corectY);
	 points3[8] = CPoint(242 * multip + corectX, 2 * multip + corectY);
	 points3[9] = CPoint(262 * multip + corectX, 16 * multip + corectY);
	 points3[10] = CPoint(276 * multip + corectX, 2 * multip + corectY);
	 points3[11] = CPoint(406 * multip + corectX, 9 * multip + corectY);
	 points3[12] = CPoint(416 * multip + corectX, 21 * multip + corectY);
	 points3[13] = CPoint(411 * multip + corectX, 41 * multip + corectY);
	 points3[14] = CPoint(416 * multip + corectX, 58 * multip + corectY);
	 points3[15] = CPoint(417 * multip + corectX, 130 * multip + corectY);
	 points3[16] = CPoint(407 * multip + corectX, 149 * multip + corectY);
	 points3[17] = CPoint(411 * multip + corectX, 232 * multip + corectY);
	 points3[18] = CPoint(414 * multip + corectX, 241 * multip + corectY);
	 points3[19] = CPoint(406 * multip + corectX, 325 * multip + corectY);
	 points3[20] = CPoint(414 * multip + corectX, 408 * multip + corectY);
	 points3[21] = CPoint(375 * multip + corectX, 400 * multip + corectY);
	 points3[22] = CPoint(377 * multip + corectX, 408 * multip + corectY);
	 points3[23] = CPoint(322 * multip + corectX, 408 * multip + corectY);
	 points3[24] = CPoint(318 * multip + corectX, 404 * multip + corectY);
	 points3[25] = CPoint(242 * multip + corectX, 408 * multip + corectY);
	 points3[26] = CPoint(226 * multip + corectX, 418 * multip + corectY);
	 points3[27] = CPoint(216 * multip + corectX, 418 * multip + corectY);
	 points3[28] = CPoint(199 * multip + corectX, 413 * multip + corectY);
	 points3[29] = CPoint(187 * multip + corectX, 418 * multip + corectY);
	 points3[30] = CPoint(162 * multip + corectX, 404 * multip + corectY);
	 points3[31] = CPoint(98 * multip + corectX, 408 * multip + corectY);
	 points3[32] = CPoint(77 * multip + corectX, 404 * multip + corectY);
	 points3[33] = CPoint(26 * multip + corectX, 406 * multip + corectY);
	 points3[34] = CPoint(4 * multip + corectX, 394 * multip + corectY);
	 points3[35] = CPoint(9 * multip + corectX, 374 * multip + corectY);
	 points3[36] = CPoint(6 * multip + corectX, 345 * multip + corectY);
	 points3[37] = CPoint(15 * multip + corectX, 277 * multip + corectY);
	 points3[38] = CPoint(5 * multip + corectX, 264 * multip + corectY);
	 points3[39] = CPoint(5 * multip + corectX, 217 * multip + corectY);
	 points3[40] = CPoint(15 * multip + corectX, 209 * multip + corectY);
	 points3[41] = CPoint(2 * multip + corectX, 95 * multip + corectY);
	 points3[42] = CPoint(8 * multip + corectX, 78 * multip + corectY);
	 points3[43] = CPoint(9 * multip + corectX, 49 * multip + corectY);
	 points3[44] = CPoint(5 * multip + corectX, 33 * multip + corectY);
	 pDC->Polygon(points3, 45);
}

 void Field::DrawField(CDC& pDC) {
	 CRect rect;
	 GetClientRect(&rect);

	 if ((this->gameParent == nullptr) || (this->gameParent->GetBoard() == nullptr))
		 return;
	 
	 int fieldSize = this->gameParent->GetBoard()->GetBoardSize();
	 CDC Mem;
	 CBitmap membt;
	 Mem.CreateCompatibleDC(&pDC);
	 membt.CreateCompatibleBitmap(&pDC, rect.Width(), rect.Height());
	 CBitmap* pOldBitmap = Mem.SelectObject(&membt);

	 CPen pen, pen1, blackpen;
	 CBrush brush, back, back1, back2, brush1, Whitebrush, blackbrush;
	 CFont font;
	 HGDIOBJ oldPen;
	 pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	 pen1.CreatePen(PS_NULL, 0, 1);
	 blackpen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	 brush.CreateSolidBrush(RGB(180, 0, 0));
	 brush1.CreateSolidBrush(RGB(220, 0, 0));
	 Whitebrush.CreateSolidBrush(RGB(255, 255, 255));
	 back.CreateSolidBrush(RGB(110, 18, 15));
	 back1.CreateSolidBrush(RGB(23, 20, 20));
	 back2.CreateSolidBrush(RGB(149, 21, 15));
	 font.CreatePointFont(200, L"Satyr SP");
	 blackbrush.CreateSolidBrush(RGB(125, 17, 10));

	 Mem.SelectObject(pen1);
	 Mem.SelectObject(back1);
	 Mem.Rectangle(rect.left, rect.top, rect.right + 1, rect.bottom + 1);
	 Mem.SelectObject(pen);
	 Mem.SelectObject(back);
	 DrawCant(&Mem);
	 Mem.SelectObject(back2);
	 Mem.Rectangle(CORRECTNUM + 2, CORRECTNUM + 2, rect.right - CORRECTNUM, rect.bottom - CORRECTNUM);

	 Mem.SelectObject(blackbrush);
	 int hSize = (rect.right - 2 * CORRECTNUM) / fieldSize;
	 int vSize = (rect.bottom - 2 * CORRECTNUM) / fieldSize;
	 for (int j = 1; j < fieldSize; j += 2) {
		 for (int i = 1; i < fieldSize; i += 2) {
			 Mem.Rectangle((CORRECTNUM + 2) + (hSize * i), CORRECTNUM + 2 + (j - 1) * vSize, (CORRECTNUM + hSize) + (hSize * i), CORRECTNUM + 1 + j * vSize);
			 Mem.Rectangle((CORRECTNUM + 2) + hSize * (i - 1), CORRECTNUM + 2 + j * vSize, (CORRECTNUM + hSize) + hSize * (i - 1), CORRECTNUM + 1 + (j + 1) * vSize);
		 }
	 }

	 Mem.SelectObject(back1);
	 DrawIcons(&Mem);

	 for (int i = 0; i < fieldSize + 1; i++) {
		 Mem.MoveTo(CORRECTNUM + i * hSize, CORRECTNUM);
		 Mem.LineTo(CORRECTNUM + i * hSize, rect.bottom - 2 - CORRECTNUM);
		 Mem.MoveTo(CORRECTNUM - 1, i * vSize + CORRECTNUM);
		 Mem.LineTo(rect.right - 1 - CORRECTNUM, i * vSize + CORRECTNUM);
	 }
	 Mem.SetTextAlign(TA_CENTER | TA_CENTER);
	 Mem.SetBkMode(TRANSPARENT);
	 int glowSize = 1;
	 for (int i = 1; i < fieldSize + 1; i++) {

		 Mem.SetTextColor(RGB(255, 255, 224));
		 CString coords;
		 char alph = '@' + i;
		 CString abc;
		 abc.Format(L"%c", alph);
		 coords.Format(L"%d", i);
		 Mem.SelectObject(font);
		 for (int dx = -glowSize; dx <= glowSize; dx++) {
			 for (int dy = -glowSize; dy <= glowSize; dy++) {
				 Mem.TextOutW(CORRECTNUM / 2 + dx, i * vSize - 7 + dy, abc);
				 Mem.TextOutW(rect.right - CORRECTNUM / 2 + dx, i * vSize - 7 + dy, abc);
				 Mem.TextOutW(i * hSize + 7 + dx, CORRECTNUM / 8 + dy, coords);
				 Mem.TextOutW(i * hSize + 7 + dx, rect.bottom - CORRECTNUM / 1.1 + dy, coords);
			 }
		 }
		 Mem.SetTextColor(RGB(0, 0, 0));
		 Mem.TextOutW(CORRECTNUM / 2, i * vSize - 7, abc);
		 Mem.TextOutW(rect.right - CORRECTNUM / 2, i * vSize - 7, abc);
		 Mem.TextOutW(i * hSize + 7, CORRECTNUM / 8, coords);
		 Mem.TextOutW(i * hSize + 7, rect.bottom - CORRECTNUM / 1.1, coords);
	 }
	 this->HighlightSelectoin(Mem);
	 for (int x = 1; x <= fieldSize; x++) {
		 for (int y = 1; y <= fieldSize; y++) {
			 switch (this->gameParent->GetBoard()->GetCell(x,y))
			 {
			 case CELLTYPE_PWHITE:
				 this->DrawPers(1, Mem, this->GetRectFromField(x, y));
				 break;
			 case CELLTYPE_WOMWHITE:
				 this->DrawPers(2, Mem, this->GetRectFromField(x, y));
				 break;
			 case CELLTYPE_PBLACK:
				 this->DrawPers(3, Mem, this->GetRectFromField(x, y));
				 break;
			 case CELLTYPE_WOMBLACK:
				 this->DrawPers(4, Mem, this->GetRectFromField(x, y));
				 break;
			 }
		 }
	 } 
	 pDC.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &Mem, 0, 0, SRCCOPY);
	 pen.DeleteObject();
	 blackpen.DeleteObject();
	 brush.DeleteObject();
	 brush1.DeleteObject();
	 Whitebrush.DeleteObject();
	 back.DeleteObject();
	 back2.DeleteObject();
	 font.DeleteObject();
	 blackbrush.DeleteObject();
	 membt.DeleteObject();
	 Mem.DeleteDC();
 }

bool Field::RegisterClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, FIELD_CLASSNAME, &wndcls)))
	{
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;

		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = FIELD_CLASSNAME;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}
    return TRUE;
}


void Field::OnPaint()
{
	static int counter = 0;
	CPaintDC dc(this);
	DrawField(dc);
}

BOOL Field::OnEraseBkgnd(CDC* pDC) {
	DrawField(*pDC);
	return TRUE;
}

void Field::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect rect;
	GetClientRect(&rect);
	static int dxpos, dypos;
	int xpos, ypos;
	if ((bGameInProgress) && (this->gameParent->GetCurrentPlayer()->IsHuman())) {
		if ((this->gameParent == nullptr) || (this->gameParent->GetBoard() == nullptr))
			return;
		if (point.x > CORRECTNUM && point.y > CORRECTNUM && point.x < rect.right - CORRECTNUM && point.y < rect.bottom - CORRECTNUM) {
			if (countclick == 0) {
				this->GetFieldPosition(point, dxpos, dypos);
				if (this->gameParent->GetBoard()->GetCell(dxpos, dypos) == CELLTYPE_PWHITE || this->gameParent->GetBoard()->GetCell(dxpos, dypos) == CELLTYPE_PBLACK || this->gameParent->GetBoard()->GetCell(dxpos, dypos) == CELLTYPE_WOMWHITE || this->gameParent->GetBoard()->GetCell(dxpos, dypos) == CELLTYPE_WOMBLACK) {

					if ((SelectedX != dxpos) || (SelectedY != dypos)) {
						SelectedX = dxpos;
						SelectedY = dypos;
					}
					countclick++;
					this->Invalidate();
				}
			}
			else {
				this->GetFieldPosition(point, xpos, ypos);
				if (this->gameParent->GetBoard()->GetCell(xpos, ypos) != CELLTYPE_EBLACK) {
					AfxMessageBox(L"Недостаточно маны!");
				}
				else {
					if (this->gameParent->GetCurrentPlayer()->MakeMove(0, 0, dxpos, dypos, xpos, ypos) == true) {
						if (this->CheckEndCondition()) {
							this->SetGameInProgress(false);
							this->gameParent->Invalidate();
						}												
						this->gameParent->TogglePlayer();
						this->Invalidate();					
					}
					SelectedX = -20;
					SelectedY = -20;
					countclick = 0;
				}

				this->Invalidate();
			}
		}
	}
	CWnd::OnLButtonDown(nFlags, point);
}

bool Field::CheckEndCondition() {
	if (this->gameParent->GetBoard()->CheckEndConditionScorecounter()) {
		if (this->gameParent->GetCurrentPlayer()->IsHuman()) {
			CString str;
			str.Format(L"Игрок %s победил!", this->gameParent->GetCurrentPlayer()->GetName());
			AfxMessageBox(str);
		}
		
		return true;
		
	}
	return false;
}

void Field::GetFieldPosition(CPoint point, int& xpos, int& ypos)
{
	CRect rect;
	if ((this->gameParent == nullptr) || (this->gameParent->GetBoard() == nullptr))
		return;
	int fieldSize = this->gameParent->GetBoard()->GetBoardSize();
	GetClientRect(&rect);
	int hSize = (rect.right - 2 * CORRECTNUM) / fieldSize;
	int vSize = (rect.bottom - 2 * CORRECTNUM) / fieldSize;
	for (int i = 1; i <= fieldSize; i++) {

		if ((point.x > CORRECTNUM + (i - 1) * hSize) && (point.x < CORRECTNUM * (i + 2) * hSize))
			xpos = i;
		if ((point.y > CORRECTNUM + (i - 1) * vSize) && (point.y < CORRECTNUM * (i + 2) * vSize))
			ypos = i;
	}
}

void Field::OnDestroy()
{
	CWnd::OnDestroy();
	/*DestroyField();*/
}

void Field::StartPositions()
{
	int fieldSize = this->gameParent->GetBoard()->GetBoardSize();
	for (int j = 1; j < fieldSize; j++) {
		this->gameParent->GetBoard()->SetCell(CELLTYPE_EWHITE, 8, j + 1, 1, 4, CELLTYPE_EBLACK);
		this->gameParent->GetBoard()->SetCell(CELLTYPE_EBLACK, 8, 5, 1, 4, CELLTYPE_EBLACK);
	}
	this->gameParent->GetBoard()->SetCell(CELLTYPE_PWHITE, 8, 3, 1, 4, CELLTYPE_EBLACK);
	this->gameParent->GetBoard()->SetCell(CELLTYPE_PBLACK, 8, 7, 1, 4, CELLTYPE_EBLACK);
}


CRect Field::GetRectFromField(int x, int y)
{
	CRect rect;
	GetClientRect(&rect);
	if ((this->gameParent == nullptr) || (this->gameParent->GetBoard() == nullptr))
		return CRect(0, 0, 0, 0);
	int fieldSize = this->gameParent->GetBoard()->GetBoardSize();
	int hSize = (rect.right - 2 * CORRECTNUM) / fieldSize;
	int vSize = (rect.bottom - 2 * CORRECTNUM) / fieldSize;
	rect.left = CORRECTNUM + (x - 1) * hSize + 1;
	rect.top = CORRECTNUM + (y - 1) * vSize + 1;
	rect.right = CORRECTNUM + x * hSize - 1;
	rect.bottom = CORRECTNUM + y * vSize - 1;
	return rect;
}


void Field::OnMouseMove(UINT nFlags, CPoint point)
{
	int x, y;
	GetFieldPosition(point, x, y);
	if ((SelectX != x) || (SelectY != y)) {
		SelectX = x;
		SelectY = y;
	
		//this->InvalidateRect(uprect);
		this->Invalidate();
	}
	TRACKMOUSEEVENT tme;
	tme.cbSize = sizeof(tme);
	tme.hwndTrack = this->m_hWnd;
	tme.dwFlags = TME_LEAVE;
	tme.dwHoverTime = HOVER_DEFAULT;
	TrackMouseEvent(&tme);
	CWnd::OnMouseMove(nFlags, point);
}


void Field::HighlightSelectoin(CDC& dc)
{
	if ((SelectX < 0) || (SelectY < 0))
		return;
	rectitok = GetRectFromField(SelectX, SelectY);
	CRect select = GetRectFromField(SelectedX, SelectedY);
	CBrush brush, brush1;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	brush.CreateSolidBrush(RGB(35, 30, 30));
	brush1.CreateSolidBrush(RGB(67, 76, 82));
	HGDIOBJ oldBrush = dc.SelectObject(brush);
	dc.Rectangle(rectitok);
	oldBrush = dc.SelectObject(brush1);
	dc.SelectObject(pen);
	dc.Rectangle(select);
	brush.DeleteObject();
	brush1.DeleteObject();
	pen.DeleteObject();
}


void Field::OnMouseLeave()
{
	SelectX = -1;
	SelectY = -1;
	
	CWnd::OnMouseLeave();
}


void Field::OnRButtonUp(UINT nFlags, CPoint point)
{
	SelectedX = -20;
	SelectedY = -20;
	countclick = 0;

	CWnd::OnRButtonUp(nFlags, point);
}
void Field::SetGameInProgress(bool inProgress) {
	if (bGameInProgress != inProgress) {
		this->bGameInProgress = inProgress;
		this->gameParent->SetGameInProgress(inProgress);
		if (inProgress)
			SetTimer(TIMER_ID, 500, NULL);
		else
			KillTimer(TIMER_ID);
	}
}

void Field::OnTimer(UINT_PTR nIDEvent)
{
	if ((bGameInProgress) && (!this->gameParent->GetCurrentPlayer()->IsHuman())) {
		if ((this->gameParent == nullptr) || (this->gameParent->GetBoard() == nullptr))
			return;

		if (this->gameParent->GetCurrentPlayer()->MakeMove(0, 0, 0, 0, 0, 0) == true) {
			if (this->CheckEndCondition()) {
				this->SetGameInProgress(false);
				CString str;
				str.Format(L"Игрок %s победил!", this->gameParent->GetCurrentPlayer()->GetName());
				this->gameParent->Invalidate();
				AfxMessageBox(str);
			}
			this->gameParent->TogglePlayer();
			this->Invalidate();
		}		
		this->Invalidate();
	}
	CWnd::OnTimer(nIDEvent);
}
