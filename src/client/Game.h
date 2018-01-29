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

#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "RemotePlayer.h"

class Game {
private:
	Board *board;
	Player *black;
	Player *white;
	bool first;
	bool AIGame;
	bool remoteGame;
public:
	Game(Board*, bool = false, bool = false);
	void Run();
	bool End();
	virtual ~Game();
};

#endif /* GAME_H_ */
