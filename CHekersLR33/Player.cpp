#include "pch.h"
#include "Player.h"

void Player::SetupPlayer(CString name, CellType cellType, CellType dcellType, CellType wcellType) {
	this->name = name;
	this->cellType = cellType;
	this->dcellType = dcellType;
	this->wcellType = wcellType;
}

void Player::SetBoard(ChekersBoard* board) {
	this->board = board;
}

CString Player::GetName() {
	return this->name;
}