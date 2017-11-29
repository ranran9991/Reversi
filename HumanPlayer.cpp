#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player() { }

void HumanPlayer::MakeMove() {
	int x, y;
	cout << sign << ": It's your move." << endl;
	// if the player has possible moves
	if (PossibleMoveExists()) {
		// print the possible moves
		cout << "Your possible moves: ";
		board->ShowPossibleMoves(sign);
		// ask from player for his next move
		cout << "\n\nPlease enter your move row,col: ";
		cin >> x >> y;
		// make the move, if illegal, ask again
		while(!board->MakeMove(x, y, sign)) {
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

HumanPlayer::~HumanPlayer() { }