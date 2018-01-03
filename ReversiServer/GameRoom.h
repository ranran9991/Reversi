/*
 * GameRoom.h
 *
 *  Created on: Jan 3, 2018
 *      Author: ron
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
