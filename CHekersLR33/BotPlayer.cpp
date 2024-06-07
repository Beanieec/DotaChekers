#pragma once
#include "pch.h"
#include "BotPlayer.h"

bool BotPlayer::IsHuman() {
	return false;
}

bool BotPlayer::MakeMove(int bufdcol, int bufdrow, int dcol, int drow, int col, int row) {

	std::vector<MonteCarlo*> evaluators;
	if (this->board->onlyFight(this->cellType)) {
		std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Fightcor;
		/*Fightcor.clear();
		Fightcor.shrink_to_fit();*/
		this->board->FightStep(this->cellType, &Fightcor);
		for (const auto& coord : Fightcor) {
			mdrow = coord.first.first;
			mdcol = coord.first.second;
			mrow = coord.second.first;
			mcol = coord.second.second;
			if (onlyfightcount != onmorecount) {
				std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> filtrFightcor;
				if (coord.first.first == bufdrow && coord.first.second == bufdcol) {
					filtrFightcor.push_back(coord);
					for (const auto& coord : filtrFightcor) {
						mdrow = coord.first.first;
						mdcol = coord.first.second;
						mrow = coord.second.first;
						mcol = coord.second.second;
					}
				}
			}
			evaluators.push_back(new MonteCarlo(this->board, 200, (this->cellType == CELLTYPE_PWHITE) ? CELLTYPE_PBLACK : CELLTYPE_PWHITE, mdrow, mdcol, mrow, mcol));
		}
	}
	else {
		std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Simplcor;
		this->board->SimpleStep(this->cellType, &Simplcor);
		if (Simplcor.empty()) {
			return true;
		}
		for (const auto& coord : Simplcor) {
			mdrow = coord.first.first;
			mdcol = coord.first.second;
			mrow = coord.second.first;
			mcol = coord.second.second;
			evaluators.push_back(new MonteCarlo(this->board, 200, (this->cellType == CELLTYPE_PWHITE) ? CELLTYPE_PBLACK : CELLTYPE_PWHITE, mdrow, mdcol, mrow, mcol));
		}	
	}
	for (int i = 0; i < evaluators.size(); i++) {
		evaluators[i]->Evaluted();
	}
	int biggestVic = -1;
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		if (this->cellType == CELLTYPE_PWHITE) {
			if ((*evaluator)->GetVictor() > biggestVic)
				biggestVic = (*evaluator)->GetVictor();
		}
		else
		{
			if ((*evaluator)->GetLose() > biggestVic)
				biggestVic = (*evaluator)->GetLose();
		}
	std::vector<MonteCarlo*> biggestWinEvaluaters;
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++) {
		int numVictories;
		if (this->cellType == CELLTYPE_PWHITE)
			numVictories = (*evaluator)->GetVictor();
		else
			numVictories = (*evaluator)->GetLose();
		if (numVictories == biggestVic)
			biggestWinEvaluaters.push_back((*evaluator));
	}
	
	mdcol = biggestWinEvaluaters[0]->dGetYpos();
	mdrow = biggestWinEvaluaters[0]->dGetXpos();
	mcol = biggestWinEvaluaters[0]->GetYpos();
	mrow = biggestWinEvaluaters[0]->GetXpos();
	
	//повтор удара
	if (onlyfightcount != onmorecount) {
		if (this->board->CheckLegal(mcol, mrow, bufdcol, bufdrow, mdcol, mdrow, this->cellType)) {
			if (this->board->onlyFightRule(mcol, mrow, mdcol, mdrow, this->cellType)) {
				if (this->board->Woman(mrow, this->cellType)) {
					this->board->SetCell(mcol, mrow, this->wcellType, mdcol, mdrow, this->dcellType);
				}
				else if (this->board->iisWoman(mdcol, mdrow)) {
					this->board->SetCell(mcol, mrow, this->wcellType, mdcol, mdrow, this->dcellType); //отрисовка хода дамки
				}
				else {
					this->board->SetCell(this->cellType, mcol, mrow, mdcol, mdrow, this->dcellType);
				}
				if (this->board->OneMore(mcol, mrow, mdcol, mdrow, this->cellType)) {
					/*board->Show();*/
					return MakeMove(mcol, mrow, 0, 0, 0, 0);
				}
				else
				{
					onlyfightcount++;
					for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
						delete (*evaluator);
					evaluators.clear();
					biggestWinEvaluaters.clear();
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
	//первый удар
	if (this->board->onlyFight(this->cellType)) { // есть удар
		if (this->board->onlyFightRule(mcol, mrow, mdcol, mdrow, this->cellType)) { //удар правильный для шашки
			if (this->board->Woman(mrow, this->cellType)) { //становление дамки [8]
				this->board->SetCell(mcol, mrow, this->wcellType, mdcol, mdrow, this->dcellType); //отрисовка хода дамки
			}
			else if (this->board->iisWoman(mdcol, mdrow)) {
				this->board->SetCell(mcol, mrow, this->wcellType, mdcol, mdrow, this->dcellType); //отрисовка хода дамки
			}
			else {
				this->board->SetCell(this->cellType, mcol, mrow, mdcol, mdrow, this->dcellType); //отрисовка хода шашки
			}
			if (this->board->OneMore(mcol, mrow, mdcol, mdrow, this->cellType)) { // есть ещё удар
				/*board->Show();*/
				onmorecount++;
				return MakeMove(mcol, mrow, 0, 0, 0, 0);
			}
			else
			{
				for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
					delete (*evaluator);
				evaluators.clear();
				biggestWinEvaluaters.clear();
				return true; //удар совершён - конец хода
			}
		}
		else {
			for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
				delete (*evaluator);
			evaluators.clear();
			biggestWinEvaluaters.clear();
			return false; // удар есть, но бьёшь не так
		}
	}
	//простые ходы
	if (this->board->CheckLegal(mcol, mrow, mdcol, mdrow, this->cellType, this->wcellType)) { //правила простого хода шашки
		if (this->board->Woman(mrow, this->cellType)) { //становление дамки
			this->board->SetCell(mcol, mrow, this->wcellType, mdcol, mdrow, this->dcellType); //отрисовка хода дамки
		}
		else if (this->board->iisWoman(mdcol, mdrow)) { //является ли пешка дамкой
			this->board->SetCell(mcol, mrow, this->wcellType, mdcol, mdrow, this->dcellType); //отрисовка хода дамки
		}
		else {
			this->board->SetCell(this->cellType, mcol, mrow, mdcol, mdrow, this->dcellType); //отрисовка хода шашки
		}
		for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
			delete (*evaluator);
		evaluators.clear();
		biggestWinEvaluaters.clear();
		return true;
	}
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		delete (*evaluator);
	evaluators.clear();
	biggestWinEvaluaters.clear();
	return false;
}