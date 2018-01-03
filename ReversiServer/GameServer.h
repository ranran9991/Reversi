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

#ifndef GAMESERVER_H_
#define GAMESERVER_H_
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "CommandManager.h"
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
	vector<int> clientList;
	/*
	 * This holds the whole list of clients
	 * it is used to close every connection in case
	 * the server closes unexpectedly or through the exit command
	 */


public:
	GameServer(int port);
	/*
	 * Getting the port from a config file
	 */
	GameServer(char* fileName);
	void start();
	static void* handleClient(void* );//void* for pthread usage
	static void* waitForExit(void* ); //function to wait for exit command from console
	void stop(); //stops the server and closes every client socket
};

struct CommunicationSockets{
		/*
		 * This struct will be passed to handleClient as input
		 * throw pthread_create function
		 */
		int serverSocket;
		int clientSocket;
};

#endif /* GAMESERVER_H_ */
