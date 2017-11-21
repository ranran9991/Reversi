/*
 * Board.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
#include "Player.h"

class Game {
private:
	Board *board;
	Player black;
	Player white;
public:
	Game(Board* board);
	void Move(Player);
	void Run();
	bool End();
	virtual ~Game();
};

#endif /* GAME_H_ */
