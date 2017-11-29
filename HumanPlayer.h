/*
 * HumanPlayer.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer();
	void MakeMove();
	~HumanPlayer();
};

#endif /* HumanPlayer_H_ */
