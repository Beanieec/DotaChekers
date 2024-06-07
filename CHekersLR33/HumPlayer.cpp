#include "pch.h"
#include "HumPlayer.h"

bool HumPlayer::IsHuman() {
	return true;
}

bool HumPlayer::MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row) {
	
	
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
				onmorecount++;
				return MakeMove(col, row, 0, 0, 0, 0);
			}
			else
			{
				return true; //���� �������� - ����� ����
			}
		}
		else {
			if (onmorecount == 0) {
				AfxMessageBox(L"�� ������� ������ �����");
				return false;
			}
			else
			{
				AfxMessageBox(L"�������!!!");
				onmorecount = 0;
				return false;
			}
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
	AfxMessageBox(L"������������ ���!");
	return false;
}