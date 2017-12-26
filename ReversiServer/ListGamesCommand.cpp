/*
 * listGamesCommand.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#include "ListGamesCommand.h"
#include <cstdlib> //for std::atoi
void ListGamesCommand::execute(vector<string> args) {
	/*
	 * Arg 1 = socket_sd of client
	 */
	int socket_sd = atoi(args[0].c_str());
	vector <pair<string, int> >::iterator i;
	string buffer = "Available Games: \n";
	for (i = RoomCommand::gameRooms.begin(); i != RoomCommand::gameRooms.end(); i++){
		buffer += "Name: ";
		buffer += i->first;
		buffer += '\n';
	}
	write(socket_sd, buffer.c_str(), 1024/* size of buffer */ );
}

ListGamesCommand::~ListGamesCommand() {}
