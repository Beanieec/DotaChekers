#pragma once
#include "ChekersBoard.h"
#include <string>
//#include "pch.h"

class Player
{
protected:
	ChekersBoard* board;
	CellType dcellType;
	CellType wcellType;
	CString name;
	char dletter, letter;
	/*int row, col, drow, dcol;*/
	int mrow, mcol, mdrow, mdcol;
	int onmorecount = 0;
	int onlyfightcount = 0;
public:
	CellType cellType;
	Player() {};
	virtual ~Player() {};
	void SetupPlayer(CString name, CellType cellType, CellType dcellType, CellType wcellType);
	void SetBoard(ChekersBoard* board);
	virtual bool MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row) = 0;
	virtual bool IsHuman() = 0;
	CString GetName();
};

