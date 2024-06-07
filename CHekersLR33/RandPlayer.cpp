#include "pch.h"
#include "RandPlayer.h"

bool RandPlayer::IsHuman() {
	return false;
}


bool RandPlayer::MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row) {

	if (this->board->onlyFight(this->cellType)) {
		std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Fightcor;
		this->board->FightStep(this->cellType, &Fightcor);
		for (const auto& coord : Fightcor) {
			drow = coord.first.first;
			dcol = coord.first.second;
			row = coord.second.first;
			col = coord.second.second;
			if (onlyfightcount != onmorecount) {
				std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> filtrFightcor;
				if (coord.first.first == bufdrow && coord.first.second == bufdcol) {
					filtrFightcor.push_back(coord);
					for (const auto& coord : filtrFightcor) {
						drow = coord.first.first;
						dcol = coord.first.second;
						row = coord.second.first;
						col = coord.second.second;
					}
				}
			}
		}
	}
	else {
		std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Simplcor;
		this->board->SimpleStep(this->cellType, &Simplcor);
		if (Simplcor.empty())
			return true;
		for (const auto& coord : Simplcor) {
			drow = coord.first.first;
			dcol = coord.first.second;
			row = coord.second.first;
			col = coord.second.second;
		}
	}

	//������ �����
	if (onlyfightcount != onmorecount) {
		if (this->board->CheckLegal(col, row, bufdcol, bufdrow, dcol, drow, this->cellType)) {
			if (this->board->onlyFightRule(col, row, dcol, drow, this->cellType)) {
				if (this->board->Woman(row, this->cellType)) {
					this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType);
				}
				else if (this->board->iisWoman(dcol, drow)) {
					this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
				}
				else {
					this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType);
				}
				if (this->board->OneMore(col, row, dcol, drow, this->cellType)) {
					return MakeMove(col, row, 0, 0, 0, 0);
				}
				else
				{
					onlyfightcount++;
					return true;
				}
			}
			else {
				return MakeMove(bufdcol, bufdrow, 0, 0, 0, 0);
			}
		}
		else {
			return MakeMove(bufdcol, bufdrow, 0, 0, 0, 0);
		}
	}
	//������ ����
	if (this->board->onlyFight(this->cellType)) { // ���� ����
		if (this->board->onlyFightRule(col, row, dcol, drow, this->cellType)) { //���� ���������� ��� �����
			if (this->board->Woman(row, this->cellType)) { //����������� ����� [8]
				this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
			}
			else if (this->board->iisWoman(dcol, drow)) {
				this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
			}
			else {
				this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType); //��������� ���� �����
			}
			if (this->board->OneMore(col, row, dcol, drow, this->cellType)) { // ���� ��� ����
				/*board->Show();*/
				onmorecount++;
				return MakeMove(col, row, 0, 0, 0, 0);
			}
			else
			{
				return true; //���� �������� - ����� ����
			}
		}
		else {
			return false; // ���� ����, �� ����� �� ���
		}
	}
	//������� ����
	if (this->board->CheckLegal(col, row, dcol, drow, this->cellType, this->wcellType)) { //������� �������� ���� �����
		if (this->board->Woman(row, this->cellType)) { //����������� �����
			this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
		}
		else if (this->board->iisWoman(dcol, drow)) { //�������� �� ����� ������
			this->board->SetCell(col, row, this->wcellType, dcol, drow, this->dcellType); //��������� ���� �����
		}
		else {
			this->board->SetCell(this->cellType, col, row, dcol, drow, this->dcellType); //��������� ���� �����
		}
		return true;
	}
	return false;
}