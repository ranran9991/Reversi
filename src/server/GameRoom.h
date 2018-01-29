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

#ifndef GAMEROOM_H_
#define GAMEROOM_H_
#include <string>
using namespace std;

class GameRoom {
private:

public:
	GameRoom();
	GameRoom(string, int, bool);
	string name;
	int id;
	bool wait;
	~GameRoom();
};

#endif /* GAMEROOM_H_ */
