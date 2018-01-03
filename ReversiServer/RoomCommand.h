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

#ifndef ROOMCOMMAND_H_
#define ROOMCOMMAND_H_
#include "Command.h"
#include "GameRoom.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib> //for std::atoi
using namespace std;

class RoomCommand : public Command {
	/*
	 * Commands that revolve around setting up a game
	 */
public:
	static vector <GameRoom> gameRooms;
	//this vector will contain pairs of room names
	//and the socket descriptors of the clients who created that game.
	virtual bool execute(vector <string> args)=0;
};

#endif /* ROOMCOMMAND_H_ */
