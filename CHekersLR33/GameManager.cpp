#include "pch.h"
#include "GameManager.h"
#include "HumPlayer.h"
#include "BotPlayer.h"
#include "RandPlayer.h"


GameManager::GameManager() {}

bool GameManager::Init() {
	
	return true;
}

GameManager::~GameManager() {
	delete this->player2;
	delete this->player1;
	delete this->board;
}

void GameManager::ShowBoard() {
	
}

void GameManager::MakeMove() {
	ShowBoard();
	while (!currentPlayer->MakeMove(0, 0, 0, 0, 0 ,0)) {
		std::cout << "  \033[4;41mНедопустимый ход, попробуйте ещё\033[0m" << std::endl;
		ShowBoard();
	}
	if (this->board->CheckEndConditionScorecounter()) {
		std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> sC;
		this->board->SimpleStep(this->currentPlayer->cellType, &sC);
		if (sC.empty()) {
			currentPlayer = (currentPlayer == player1) ? player2 : player1;
		}
		std::cout << "          \033[4;42m" << "Игрок " << currentPlayer->GetName() << " победил!" << "\033[0m" << std::endl;
		this->bGameFinished = true;
		ShowBoard();
		std::cout << "              \033[41mКонец...\033[0m" << std::endl;
		std::cout << "\033[32m====================================\033[0m" << std::endl;
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool GameManager::IsGameFinished() {
	return bGameFinished;
}