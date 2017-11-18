/*
 * Board.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#include "Game.h"
#include <iostream>

Game::Game(Board* board) : white(Player('O')), black(Player('X')),board(board) {
	white.SetBoard(board);
	black.SetBoard(board);
}

void Game::Run() {
	// while any of the players have a possible move
	while (true) {
		if (End()) break;
		// black makes move
		Move(black);
		if (End()) break;
		// white makes move
		Move(white);
	}
	cout << *board << endl; // print the board
	int countBlack = board->CountSign(black.GetSign());
	int countWhite = board->CountSign(white.GetSign());
	// if number of black and white is equal
	if (countBlack == countWhite) {
		cout << "It's a tie!" << endl; // print tie
		return;
	}
	// if black has more than white print white wins
	if (countBlack > countWhite) cout << black.GetSign();
	// if black has more than white print black wins
	else cout << white.GetSign();
	cout << " is the winner!" << endl;
}

bool Game::End() {
	// if any player has a possible move, return false, else return true
	return !(black.PossibleMoveExists() || white.PossibleMoveExists());
}

void Game::Move(Player player) {
	int x, y;
	cout << *board << endl << player.GetSign() << ": It's your move." << endl;
	// if the player has possible moves
	if (player.PossibleMoveExists()) {
		// print the possible moves
		cout << "Your possible moves: ";
		player.ShowPossibleMoves();
		// ask from player for his next move
		cout << "\n\nPlease enter your move row,col: ";
		cin >> x >> y;
		// make the move, if illegal, ask again
		while(!player.MakeMove(x, y)) {
			cout << "Illegal move.\nPlease enter your move row,col: ";
			cin >> x >> y;
		}
	}
	// else, print no possible moves
	else {
		cout << "No possible moves. Play passes back to the other player." <<
				" Press any key to continue. ";
		cin.ignore();
		cin.get();
		cout << endl;
	}
	cout << endl;
}

Game::~Game() { }
