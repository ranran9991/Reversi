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

#include "AIPlayer.h"

AIPlayer::AIPlayer() : Player() { }

void AIPlayer::MakeMove() {
	// if no possible moves exist
	if (!board->PossibleMoveExists(sign)) {
		// print the board and message
		cout << *board << endl;
		cout << sign << " has no possible moves, play passes back to you.\n\n";
		return;
	}

	vector<pair<int, int> > legalMoves; // this player's legal moves
	vector<pair<int, int> > otherLegalMoves; // for each move, other player's legal moves

	vector<pair<int, int> >::iterator it; // iterator to go over legal moves
	vector<pair<int, int> >::iterator itOther; // iterator to go over other's legal moves

	pair<int, int> bestMove; // move with the minimum score

	Board checkBoard, otherCheckBoard; // temporary boards to save the moves in memory

	int score; // minimum score possible
	int otherScore; // for each move, other player's maximum score

	char other = board->OtherSign(sign); // other player's sign

	legalMoves = board->GetLegalMoves(sign); // assign legal moves

	// go over legal moves
	for (it = legalMoves.begin(); it != legalMoves.end(); ++it) {
		checkBoard = *board; // assign the temporary board to be the original board
		checkBoard.MakeMove(it->first, it->second, sign); // make the move
		otherLegalMoves = checkBoard.GetLegalMoves(other); // assign other's legal moves

		// go over other's legal moves
		for (itOther = otherLegalMoves.begin(); itOther != otherLegalMoves.end();
				++itOther) {
			otherCheckBoard = checkBoard; /* assign other's temporary board to be the
											 board with the move made */
			otherCheckBoard.MakeMove(itOther->first, itOther->second, other); // make other's move

			// if this is the first move, or the highest score move, assign as the new maximum
			if (itOther == otherLegalMoves.begin() ||
					otherScore < otherCheckBoard.Score(other))
				otherScore = otherCheckBoard.Score(other);
		}
		// if this is the first move, or the lowest score move, assign as the new minimum
		if (it == legalMoves.begin() ||
				score > otherScore) {
			score = otherScore;
			bestMove = *it;
		}
	}

	board->MakeMove(bestMove.first, bestMove.second, sign); // make the best move found
	cout << *board << endl; // print the board
	// print a message about the move
	cout << sign << " played (" << bestMove.first << "," << bestMove.second << ")\n\n";
}

AIPlayer::~AIPlayer() { }
