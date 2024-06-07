#pragma once
#include "Field.h"
#include "pch.h"

// Диалоговое окно CCHekersLR33Dlg
class Field;
class CCHekersLR33Dlg : public CDialogEx
{
// Создание
public:
	CCHekersLR33Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHEKERSLR33_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	Field tttField;
	
	// Созданные функции схемы сообщений
	virtual HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonSettings();
	void CreateBoard(int size);
	void CreatePlayer1(CString name, int type);
	void CreatePlayer2(CString name, int type);
	ChekersBoard* GetBoard();
	Player* GetCurrentPlayer();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
	ChekersBoard* board;
	Player* player1;
	Player* player2;
	Player* currentPlayer;
	bool bGameInProgress = false;
public:
	afx_msg void OnDestroy();
	void SetGameInProgress(bool inProgress);
	void TogglePlayer();
	/*CButton mStartButton;*/
	int countclick = 0;
	void UpdateName();
	CString strPlayerTurn;
	afx_msg void OnBnClickedButtonsettings2();
};
