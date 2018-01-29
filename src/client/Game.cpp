/*
 * Board.h
 *
 *  Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 *
 *  Ran Elgiser
 *  ID: 322768805
 *  Exercise Grope: 05
 */

#include "Game.h"
#include <iostream>

Game::Game(Board* board, bool AIGame, bool remoteGame) :
		AIGame(AIGame), board(board), remoteGame(remoteGame) {

	if (remoteGame) {
		//Creating remote player and reading the IP and Port from clientconfig.txt
		Player *temp = new RemotePlayer("clientconfig.txt", &first);
		if(first) {
			cout << "You are X\n\n";
			black = new HumanPlayer;
			white = temp;
		}
		else {
			cout << "You are O\n\n";
			black = temp;
			white = new HumanPlayer;
		}
	}

	else {
		black = new HumanPlayer; // create new human player
		if (AIGame) white = new AIPlayer ; // if played against AI player, create AI player
		else white = new HumanPlayer; // else, create new human player
	}

	white->SetBoard(board);
	white->SetSign('O');
	black->SetBoard(board);
	black->SetSign('X');
}

void Game::Run() {
	if (AIGame || (remoteGame && first)) cout << *board << endl;
	// while any of the HumanPlayers have a possible move
	while (true) {
		if (End()) break;
		if (!AIGame && !remoteGame) cout << *board << endl;
		// black makes move
		black->MakeMove();
		if (End()) break;
		if (!AIGame && !remoteGame) cout << *board << endl;
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

Game::~Game() {
	// deleting memory allocated for board and players
	delete board;
	delete white;
	delete black;
}
