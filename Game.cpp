/*
 * Board.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#include "Game.h"
#include <iostream>

Game::Game(Board* board, bool AIGame) : AIGame(AIGame), board(board) {
	black = new HumanPlayer;
	if (AIGame) white = new AIPlayer ;
	else white = new HumanPlayer;
	white->SetBoard(board);
	white->SetSign('O');
	black->SetBoard(board);
	black->SetSign('X');
}

void Game::Run() {
	if (AIGame) cout << *board << endl;
	// while any of the HumanPlayers have a possible move
	while (true) {
		if (End()) break;
		if (!AIGame) cout << *board << endl;
		// black makes move
		black->MakeMove();
		if (End()) break;
		if (!AIGame) cout << *board << endl;
		// white makes move
		white->MakeMove();
	}
	if (!AIGame) cout << *board << endl; // print the board
	int countBlack = board->CountSign(black->GetSign());
	int countWhite = board->CountSign(white->GetSign());
	// if number of black and white is equal
	if (countBlack == countWhite) {
		cout << "It's a tie!" << endl; // print tie
		return;
	}
	// if black has more than white print white wins
	if (countBlack > countWhite) cout << black->GetSign();
	// if black has more than white print black wins
	else cout << white->GetSign();
	cout << " is the winner!" << endl;
}

bool Game::End() {
	// if any HumanPlayer has a possible move, return false, else return true
	return !(black->PossibleMoveExists() || white->PossibleMoveExists());
}

Game::~Game() { delete board; }
