#include "pch.h"
#include "PlayButton.h"
BEGIN_MESSAGE_MAP(PlayButton, CButton)
	ON_WM_PAINT()
    ON_WM_DRAWITEM()
END_MESSAGE_MAP()


void PlayButton::OnPaint()
{
	CPaintDC dc(this);
    CRect rect;
    GetClientRect(&rect);

    dc.FillSolidRect(rect, RGB(255, 0, 0));

    CString buttonText = (L"Играть");
    dc.SetTextColor(RGB(255, 255, 255));
    dc.DrawText(buttonText, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


void PlayButton::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{

    CButton::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
