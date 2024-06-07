#pragma once

#include "Player.h"
#include <thread>
class RandPlayer : public Player
{
public:
	RandPlayer() {};
	virtual ~RandPlayer() {};
	virtual bool MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row);
	virtual bool IsHuman();
};

