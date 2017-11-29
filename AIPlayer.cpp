/*
 * ALPlayer.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: ron
 */

#include "AIPlayer.h"

AIPlayer::AIPlayer() : Player() { }

void AIPlayer::MakeMove() {
	if (!board->PossibleMoveExists(sign)) {
		cout << *board << endl;
		cout << sign << " has no possible moves, play passes back to you.\n";
	}

	vector<pair<int, int> > legalMoves;
	vector<pair<int, int> > otherLegalMoves;
	vector<pair<int, int> >::iterator it;
	vector<pair<int, int> >::iterator itOther;
	pair<int, int> bestMove;
	Board checkBoard, otherCheckBoard;
	int score, otherScore;
	char other = board->OtherSign(sign);

	legalMoves = board->GetLegalMoves(sign);
	for (it = legalMoves.begin(); it != legalMoves.end(); ++it) {
		checkBoard = *board;
		checkBoard.MakeMove(it->first, it->second, sign);
		otherLegalMoves = checkBoard.GetLegalMoves(other);
		for (itOther = otherLegalMoves.begin(); itOther != otherLegalMoves.end();
				++itOther) {
			otherCheckBoard = checkBoard;
			otherCheckBoard.MakeMove(itOther->first, itOther->second, other);
			if (itOther == otherLegalMoves.begin() ||
					otherScore < otherCheckBoard.Score(other))
				otherScore = otherCheckBoard.Score(other);
		}
		if (it == legalMoves.begin() ||
				score > otherScore) {
			score = otherScore;
			bestMove = *it;
		}
	}
	board->MakeMove(bestMove.first, bestMove.second, sign);
	cout << *board << endl;
	cout << sign << " played (" << bestMove.first << "," << bestMove.second << ")\n\n";
}

AIPlayer::~AIPlayer() { }
