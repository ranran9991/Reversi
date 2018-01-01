/*
 * JoinCommand.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */
#include "JoinCommand.h"
bool JoinCommand::execute(vector<string> args) {
	/*
	 * Arg 1 = client socket_sd
	 * Arg 2 = name of game to join into
	 */
	char buffer[1024];
	string closeCommand = "close "+args[1];
	int client1_sd = 0;
	int client2_sd = atoi(args[0].c_str());
	vector<pair<string, int> >::iterator it;
	for(it = RoomCommand::gameRooms.begin(); it != RoomCommand::gameRooms.end(); it++){
		/*f
		 * Loop for finding socket_sd of the creator of the game
		 */
		if(it->first == args[1]/* name of the game */){
			client1_sd = it->second;
		}
	}
	if(client1_sd == 0){
		/*
		 * If a game that doesn't exist was given as input
		 */
		write(client2_sd, "-1", 1024 /* size of set buffer */);
		return true;
	}
	write(client2_sd, "0", 1024 /* size of set buffer */);
	for(vector<pair<string, int> >::iterator it = gameRooms.begin(); it != gameRooms.end(); it++){
		if(it->first == args[1]){
			pthread_mutex_lock(&lock);
			gameRooms.erase(it);
			pthread_mutex_unlock(&lock);
		}
	}
	//Sending 1 to creator client to show him he is the first to enter
	write(client1_sd,"1",sizeof(buffer));
	//sending 2 to joining client to show him he is the second to enter
	write(client2_sd,"2",sizeof(buffer));
	while(true){
		memset(&buffer[0], 0, sizeof(buffer));
		//taking input form client 1
		if(read(client1_sd, buffer, sizeof(buffer))<=0 || !strcmp(buffer, closeCommand.c_str())) {
			close(client1_sd);
			//Writing to the second client that the game is over
			memset(&buffer[0], 0, sizeof(buffer));
			//buffer will have "close + <name of room>"
			strcpy(buffer, closeCommand.c_str());
			write(client2_sd, buffer, sizeof(buffer));
			close(client2_sd);
			break;
		}
		cout<<buffer<<endl;
		//returning the message
		if(write(client2_sd, buffer, sizeof(buffer))<=0){
			close(client1_sd);
			close(client2_sd);
			break;
		}
		memset(&buffer[0], 0, sizeof(buffer));
		//taking input from client 2
		if(read(client2_sd, buffer, sizeof(buffer))<=0 || !strcmp(buffer, closeCommand.c_str())){
			memset(&buffer[0], 0, sizeof(buffer));
			//Writing to the second client that the game is over
			close(client1_sd);
			//buffer will have "close + <name of room>"
			strcpy(buffer, closeCommand.c_str());
			close(client2_sd);
			break;
		}
		cout<<buffer<<endl;
		//returning the message
		if(write(client1_sd, buffer, sizeof(buffer))<0){
			close(client1_sd);
			close(client2_sd);
			break;
		}
	}
	/*
	 * Removing the room from the gameRooms vector
	 */
	return false;
}

JoinCommand::~JoinCommand() {
}
