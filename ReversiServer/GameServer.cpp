/*
 * GameServer.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: ranran9991
 */

#include "GameServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib> //for std::atoi, itoa


using namespace std;
#define MAX_CONNECTED_CLIENTS 10

GameServer::GameServer(int port): port(port), serverSocket(0){
	cout<<"Server initialized through constructor";
}

GameServer::GameServer(char* fileName): serverSocket(0){
	string buffer;
	ifstream config;
	config.open(fileName);
	if(!config){
		throw "Can't open file, aborting";
	}
	while (!config.eof()) {
	    config >> buffer;
	    if(buffer == "Port"){
	    	config>>buffer; // buffer = "="
	    	config>>buffer; // buffer equals the port
	    	port = atoi(buffer.c_str());
	    	return;
	    }
	}
	config.close();
}
void GameServer::start(){
	int client1_sd;
	/*
	 * Both of these variables are used to create a changing number of threads
	 * Ill allocate a thread for each client
	 */
	vector<pthread_t *> threadList;
	int threadIndex = 0;
	pthread_t exitThread; //this thread is used to provide a way to close the server.
	CommunicationSockets sock;
	sock.serverSocket = serverSocket;
	char buffer[1024];
	//clients' variables
	struct sockaddr_in client1Address;
	socklen_t client1AddressLen = 0;
	/*
	 * Creating thread that will listen to the exit command
	 */
	if(pthread_create(&exitThread, NULL, waitForExit, this )){
		throw "Error opening thread";
	}
	//cleaning buffer
	memset(&buffer[0], 0, sizeof(buffer));
	//Creating the socket
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocket == -1){
		throw "Error opening socket";
	}
	//Creating socket address variable for binding
	struct sockaddr_in serverAddress;
	//initializing it to 0's
	bzero((void *)&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	//Gets connections from anything
	serverAddress.sin_addr.s_addr= INADDR_ANY;
	serverAddress.sin_port = htons(port);
	//binding
	if (bind(serverSocket, (struct sockaddr* )&serverAddress,
		sizeof(serverAddress)) == -1){
		throw "Error on binding";
	}
	listen(serverSocket, MAX_CONNECTED_CLIENTS);
	//If a game has ended, start a new one
	while(true){
		threadList.push_back(new pthread_t);
		//Accepting client
		client1_sd = accept(serverSocket,
					(struct sockaddr* )&client1Address,
				 	 &client1AddressLen);
		cout<< client1_sd;
		//pushing the client into the client vector
		clientList.push_back(client1_sd);
		sock.clientSocket = client1_sd;
		if(pthread_create(threadList[threadIndex], NULL, handleClient, &sock)){
			throw "Error opening thread";
		}
		threadIndex++;
	}
}

void* GameServer::handleClient(void* socket) {
	//argument vector for inserting into CommandManager
	vector<string> args;
	bool chooseMoreCommands = true;
	char buffer[1024];
	char* token;//for tokenizing the buffer
	string command;//holds the command (Ex: "start", "join")
	CommunicationSockets* sock = (CommunicationSockets *)socket;
	CommandManager com;
	stringstream ss;
	while(chooseMoreCommands){
		//parsing input from user:
		ss.str("");
		ss.clear();
		ss << sock->clientSocket;
		args.push_back(ss.str()); //every command needs the socket_id of the client
		cout << "wait" << endl;
		read(sock->clientSocket, buffer, sizeof(buffer));
		cout << "read " << buffer << endl;
		//tokenizing the string
		token = strtok(buffer, " ");
		cout << token << endl;
		//command = the first token in buffer which is the command itself.
		command = token;
		token = strtok(NULL, " ");
		while(token){
			//strtok loop, iterating over input
			args.push_back(token);
			cout << token << endl;
			token = strtok(NULL, " ");
		}
		//execute the command
		chooseMoreCommands = com.executeCommand(command, args);
		cout << chooseMoreCommands << endl;
		args.clear();
	}
	return NULL;
}

void GameServer::stop() {
	char end[1024 /*size of buffer*/] = "End";
	for(vector<int>::iterator it = clientList.begin(); it!=clientList.end(); it++){
		write(*it, end, 1024 /*size of buffer*/);
		close(*it);
	}
	close(serverSocket);
}

void* GameServer::waitForExit(void* server) {
	string input;
	GameServer* serv = (GameServer *)(server);
	while(true){
		cin>>input;
		if(input == "exit"){
			serv->stop();
			exit(0);
		}
	}
}
