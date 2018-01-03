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

#include "ListGamesCommand.h"
#include <cstdlib> //for std::atoi
bool ListGamesCommand::execute(vector<string> args) {
	/*
	 * Arg 1 = socket_sd of client
	 */
	int socket_sd = atoi(args[0].c_str());
	int gameCounter = 0;
	vector <GameRoom>::iterator i;
	string buffer = "Available games: \n";
	for (i = RoomCommand::gameRooms.begin(); i != RoomCommand::gameRooms.end(); i++){
		if (i->wait) {
			buffer += "Name: ";
			buffer += i->name;
			buffer += '\n';
			gameCounter++;
		}
	}
	if (!gameCounter) buffer += "No games available\n";
	write(socket_sd, buffer.c_str(), 1024/* size of buffer */ );
	return true;
}

ListGamesCommand::~ListGamesCommand() {}
