/*
 * StartCommand.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#include "StartCommand.h"
pthread_mutex_t lock;
void StartCommand::execute(vector <string> args) {
	/*
	 * Arg 1 = socket_sd of the client
	 * Arg 2 = game name
	 */
	vector<pair<string, int> >::iterator it;
	for (it = gameRooms.begin(); it !=gameRooms.end(); it++ ){
		if(it->first == args[1]){
			/*
			 * Send "-1" to the client if a game with the same name already exists
			 */
			write(atoi(args[0].c_str()), "-1", 1024 /* size of set buffer */);
			return;
		}
	}
	//inserts to the string the pair <name of the game, socket_sd of client
	pthread_mutex_lock(&lock);
	RoomCommand::gameRooms.push_back(make_pair(args[1],atoi(args[0].c_str())));
	pthread_mutex_unlock(&lock);
	/*
	 * If the creation was successful, write 0;
	 */
	write(atoi(args[0].c_str()), "0", 1024 /* size of set buffer */);
}

StartCommand::~StartCommand() {
}
