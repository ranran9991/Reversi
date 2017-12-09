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
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib> //for std::atoia


using namespace std;
#define MAX_CONNECTED_CLIENTS 2

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
	int client1_sd, client2_sd;
	char buffer[1024];
	//clients' variables
	struct sockaddr_in client1Address, client2Address;
	socklen_t client1AddressLen = 0, client2AddressLen = 0;
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
		//start listening for clients
		cout<<"Waiting for connections"<<endl;
		//Accepting first client
		client1_sd = accept(serverSocket,
					(struct sockaddr* )&client1Address,
				 	 &client1AddressLen);
		cout<< "Client 1 entered!"<<endl;
		//Sending 1 to him to show him he is the first to enter
		buffer[0] = '1';
		write(client1_sd,buffer,sizeof(buffer));
		//Accepting second client
		client2_sd = accept(serverSocket,
					(struct sockaddr* )&client1Address,
					&client1AddressLen);
		cout<<"Client 2 entered!"<<endl;
		//Sending 2 to him to show him he is the second to enter
		buffer[0] = '2';
		write(client2_sd,buffer,sizeof(buffer));
		//Sending to first player to make him know second player connected
		write(client1_sd,buffer,sizeof(buffer));
		while(true){
			memset(&buffer[0], 0, sizeof(buffer));
			//taking input form client 1
			if(read(client1_sd, buffer, sizeof(buffer))<=0){
				throw "Error on reading in server";
			}
			if(!strcmp(buffer, "End")){
				close(client1_sd);
				close(client2_sd);
				break;
			}
			cout<<buffer<<endl;
			//returning the message
			if(write(client2_sd, buffer, sizeof(buffer))<=0){
				throw "Error on writing in server";
			}
			memset(&buffer[0], 0, sizeof(buffer));
			//taking input from client 2
			if(read(client2_sd, buffer, sizeof(buffer))<=0){
				throw "Error on reading from server";
			}
			if(strcmp(buffer, "End") == 0){
				close(client1_sd);
				close(client2_sd);
				break;
			}
			cout<<buffer<<endl;
			//returning the message
			if(write(client1_sd, buffer, sizeof(buffer))<0){
				throw "Error on writing to server";
			}
		}
	}
}
