/*
 * StartCommand.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#include "StartCommand.h"
pthread_mutex_t lock;
bool StartCommand::execute(vector <string> args) {
	/*
	 * Arg 1 = socket_sd of the client
	 * Arg 2 = game name
	 */
	char buffer[1024];
	memset(buffer, '\0', 1024);
	vector<GameRoom>::iterator it;
	for (it = gameRooms.begin(); it !=gameRooms.end(); it++ ){
		if(it->name == args[1] && it->wait){
			/*
			 * Send "-1" to the client if a game with the same name already exists
			 */
			buffer[0] = '-';
			buffer[1] = '1';
			write(atoi(args[0].c_str()), buffer, 1024 /* size of set buffer */);
			return true;
		}
	}
	//inserts to the string the pair <name of the game, socket_sd of client
	pthread_mutex_lock(&lock);
	RoomCommand::gameRooms.push_back(GameRoom(args[1],atoi(args[0].c_str()),true));
	pthread_mutex_unlock(&lock);
	/*
	 * If the creation was successful, write 0;
	 */
	buffer[0] = '0';
	write(atoi(args[0].c_str()), buffer, 1024 /* size of set buffer */);
	return false;
}

StartCommand::~StartCommand() {
}
