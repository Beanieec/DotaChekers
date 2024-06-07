#pragma once
//#include "CHekersLR33Dlg.h"
#include "pch.h"


// Field
class CCHekersLR33Dlg;
class Field : public CWnd
{
	DECLARE_DYNAMIC(Field)

public:
	Field();
	virtual ~Field();

protected:
	DECLARE_MESSAGE_MAP()
private:
	bool RegisterClass();
public:
	afx_msg void OnPaint();
private:
	
public:
	
	//void ClearField();
	void StartPositions();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	/*void LoadBitmapFromResource(UINT resourceID);*/

private:

	BOOL OnEraseBkgnd(CDC* pDC);
	void GetFieldPosition(CPoint point, int& xpos, int& ypos);
	/*int** fields;*/
	/*void InitField();*/
	/*void DestroyField();*/
	void DrawCant(CDC* pDC);
	void DrawPers(int kind, CDC& pDC, CRect rect);
	void DrawIcons(CDC* pDC);
	void DrawField(CDC& pDC);

public:
	afx_msg void OnDestroy();
private:
	CRect GetRectFromField(int x, int y);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	CRect rectitok;
	int countclick = 0;
	int SelectX, SelectedX;
	int SelectY, SelectedY;
	bool bGameInProgress;
	CCHekersLR33Dlg* gameParent;
	void HighlightSelectoin(CDC& dc);
public:
	void SetGameParent(CCHekersLR33Dlg* p);
	void SetGameInProgress(bool inProgress);
	afx_msg void OnMouseLeave();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	bool CheckEndCondition();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


