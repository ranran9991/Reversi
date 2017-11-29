/*
 * ALPlayer.h
 *
 *  Created on: Nov 25, 2017
 *      Author: ron
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
