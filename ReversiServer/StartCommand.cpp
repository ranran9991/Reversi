/*
 * StartCommand.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#include "StartCommand.h"
void StartCommand::execute(vector <string> args) {
	/*
	 * Arg 1 = socket_sd of the client
	 * Arg 2 = game name
	 */
	//inserts to the string the pair <name of the game, socket_sd of client
	RoomCommand::gameRooms.push_back(make_pair(args[2],atoi(args[1].c_str())));
}

StartCommand::~StartCommand() {
}
