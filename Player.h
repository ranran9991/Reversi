/*
 * Player.h
 *
 *  Created on: Nov 25, 2017
 *      Author: ron
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Board.h"
#include <iostream>

class Player {
protected:
	Board *board;
	char sign;
public:
	Player();
	void SetSign(char);
	char GetSign();
	void SetBoard(Board*);
	virtual void MakeMove()=0;
	bool PossibleMoveExists();
	~Player();
};

#endif /* PLAYER_H_ */
