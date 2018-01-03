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

#include "JoinCommand.h"
bool JoinCommand::execute(vector<string> args) {
	/*
	 * Arg 1 = client socket_sd
	 * Arg 2 = name of game to join into
	 */
	//creating the buffer
	char buffer[1024];
	//reseting buffer
	memset(&buffer[0], 0, sizeof(buffer));
	//for a game called "gme" this string holds "close gme"
	string closeCommand = "close "+args[1];
	//this will hold the socket descriptor of the creating client
	int client1_sd = 0;
	//this will hold the socket descriptor of the joining client
	//which is given in the args vector
	int client2_sd = atoi(args[0].c_str());
	//iterator for iterating over GameRoom vector
	vector<GameRoom>::iterator it;
	for(it = RoomCommand::gameRooms.begin(); it != RoomCommand::gameRooms.end(); it++){
		/*
		 * Loop for finding socket_sd of the creator of the game
		 */
		if(it->name == args[1]/* name of the game */ && it->wait){
			client1_sd = it->id;
			it->wait = false;
			break;
		}
	}
	if(client1_sd == 0){
		/*
		 * If a game that doesn't exist was given as input
		 */
		//send -1 to the joining client
		buffer[0] = '-';
		buffer[1] = '1';
		write(client2_sd, buffer, 1024 /* size of set buffer */);
		return true;
	}
	//if everything worked properly, send 0 to the joining client
	buffer[0] = '0';
	write(client2_sd, buffer, 1024 /* size of set buffer */);
	// Sending 0 to creator client to show him everything went right
	memset(&buffer[0], 0, sizeof(buffer));
	buffer[0] = '0';
	write(client1_sd, buffer, 1024 /* size of set buffer */);
	while(true){
		/*
		 * The game loop itself:
		 * read from first client
		 * send to second client
		 * read from second client
		 * send to first client
		 */
		memset(&buffer[0], 0, sizeof(buffer));
		//taking input form client 1
		if(read(client1_sd, buffer, sizeof(buffer))<0 || !strcmp(buffer, closeCommand.c_str())) {
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
		if(read(client2_sd, buffer, sizeof(buffer))<0 || !strcmp(buffer, closeCommand.c_str())){
			memset(&buffer[0], 0, sizeof(buffer));
			//Writing to the second client that the game is over
			close(client1_sd);
			//buffer will have "close + <name of room>"
			strcpy(buffer, closeCommand.c_str());
			write(client1_sd, buffer, sizeof(buffer));
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
	 * loop for iterating over the gameRooms vector and removing the game from it
	 */
	for(it = RoomCommand::gameRooms.begin(); it != RoomCommand::gameRooms.end(); it++){
		if(it->name == args[1] and it->wait){
			//mutexing the deletion to keep away interference from different threads
			pthread_mutex_lock(&lock);
			gameRooms.erase(it);
			pthread_mutex_unlock(&lock);
			break;
		}
	}
	return false;
}

JoinCommand::~JoinCommand() { }
