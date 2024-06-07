#pragma once
#include <afxwin.h>
class PlayButton : public CButton
{
public:
	PlayButton() {};
protected:

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};

