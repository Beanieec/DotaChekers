#pragma once
//#include "pch.h"
#include "Player.h"
#include "MonteCarlo.h"



class BotPlayer :public Player
{
public:
	BotPlayer() {};
	virtual ~BotPlayer() {};
	virtual bool MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row);
	virtual bool IsHuman();
};

