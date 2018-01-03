/*
 * Room.h
 *
 *  Created on: Jan 3, 2018
 *      Author: ron
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <string>
using namespace std;

class Room {
private:

public:
	Room();
	Room(string, int, bool);
	string name;
	int id;
	bool wait;
	~Room();
};

#endif /* ROOM_H_ */
