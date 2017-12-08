/*
 * GameServer.h
 *
 *  Created on: Dec 2, 2017
 *      Author: ranran9991
 */

#ifndef GAMESERVER_H_
#define GAMESERVER_H_
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class GameServer {
	/*
	 * This server handles connecting two clients to one
	 * another. it echos one's message to the other.
	 * Note that checking the validity of the messages is
	 * the clients responsibility and not the servers.
	 */

private:
	int port;
	int serverSocket;
public:
	GameServer(int port);
	/*
	 * Getting the port from a config file
	 */
	GameServer(char* fileName);
	void start();
	void stop();
};

#endif /* GAMESERVER_H_ */
