/*
 * Board.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */
/*
 * Board.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Board.h"
#include <iostream>

class Player {
private:
	Board *board;
	char sign;
public:
	Player(char);
	char GetSign();
	void SetBoard(Board*);
	bool MakeMove(int, int);
	void ShowPossibleMoves();
	bool PossibleMoveExists();
	virtual ~Player();
};

#endif /* PLAYER_H_ */
