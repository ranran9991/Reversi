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

#ifndef AIPLAYER_H_
#define AIPLAYER_H_
#include "Player.h"

class AIPlayer : public Player {
public:
	AIPlayer();
	void MakeMove();
	~AIPlayer();
};

#endif /* AIPLAYER_H_ */
