#include "pch.h"
#include "HumPlayer.h"

bool HumPlayer::IsHuman() {
	return true;
}

bool HumPlayer::MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row) {
	
	
	if (this->board->onlyFight(this->cellType)) { // есть удар
		if (this->board->onlyFightRule(col, row, dcol, drow, this->cellType)) { //удар правильный для шашки
			if (this->board->Woman(row, this->cellType)) { //становление дамки [8]
				this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //отрисовка хода дамки
			}
			else if (this->board->iisWoman(dcol, drow)) {
				this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //отрисовка хода дамки
			}
			else {
				this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType); //отрисовка хода шашки
			}
			if (this->board->OneMore(col, row, dcol, drow, this->cellType)) { // есть ещё удар
				onmorecount++;
				return MakeMove(col, row, 0, 0, 0, 0);
			}
			else
			{
				return true; //удар совершён - конец хода
			}
		}
		else {
			if (onmorecount == 0) {
				AfxMessageBox(L"ВЫ ОБЯЗАНЫ СЪЕСТЬ ШАШКУ");
				return false;
			}
			else
			{
				AfxMessageBox(L"ДОБИВАЙ!!!");
				onmorecount = 0;
				return false;
			}
		}
	}
	//простые ходы
	if (this->board->CheckLegal(col, row, dcol, drow, this->cellType, this->wcellType)) { //правила простого хода шашки
		if (this->board->Woman(row, this->cellType)) { //становление дамки
			this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //отрисовка хода дамки
		}
		else if (this->board->iisWoman(dcol, drow)) { //является ли пешка дамкой
			this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //отрисовка хода дамки
		}
		else {
			this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType); //отрисовка хода шашки
		}
		
		return true;
	}
	AfxMessageBox(L"Недопустимый ход!");
	return false;
}