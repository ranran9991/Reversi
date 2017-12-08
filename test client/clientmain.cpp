#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
	int clientSocket,first,readValue = 1024;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct in_addr address;
	struct hostent *server;
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(!inet_aton("127.0.0.1", &address)){
		throw "Can't parse IP address";
	}
	server = gethostbyaddr((const void*)&address, sizeof address, AF_INET);
	if(server == NULL){
		throw "Host is unreachable";
	}
	serverAddr.sin_family = AF_INET;
	memcpy((char*)&serverAddr.sin_addr.s_addr,
			(char*)server->h_addr, server->h_length);
	serverAddr.sin_port = htons(8001);

	if(connect(clientSocket, (struct sockaddr *) &serverAddr,
			sizeof serverAddr)){
		throw "Error connecting server";
	}
	cout<< "connected to server"<<endl;
	//Server tells the client if he's first or second
	memset(&buffer[0], 0, sizeof(buffer));
	read(clientSocket, buffer, sizeof buffer);
	//assigning the "first" variable
	if(!strcmp(buffer,"1")){
		first = 1;
		cout<<"I am first"<<endl;
	}
	else if(!strcmp(buffer,"2")){
		first = 0;
		cout<<"I am second"<<endl;
	}
	else{
		cout<<"Error";
		return 0;
	}
	while (true)
	{
		memset(&buffer[0], 0, sizeof(buffer));
		if(first == 0){
			//read from server
			readValue = read(clientSocket, buffer, sizeof (buffer));
			if(readValue <= 1){
				throw "Error reading from socket from client 1";
			}
			cout<<buffer<<readValue<<endl;
			//print it
			memset(&buffer[0], 0, sizeof(buffer));
			//write to buffer
			if(readValue == 1024){
				cin>>buffer;
			}
			if(write(clientSocket,buffer,sizeof buffer)<1){
				throw "Error writing to server from client 1";
			}
			memset(&buffer[0], 0, sizeof(buffer));
		}
		if(first == 1){
			//write to buffer
			cin>>buffer;
			if(write(clientSocket,buffer,sizeof buffer)<1){
				throw "Error writing to server from client 2";
			}
			memset(&buffer[0], 0, sizeof(buffer));
			//read from server
			readValue = read(clientSocket, buffer, sizeof buffer);
			if(readValue < 1){
				throw "Error reading from socket from client 2";
			}
			cout<<buffer<<endl;

<<<<<<< HEAD
		}
	}

	return 0;
=======
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
	//Server tells the client if hes first or second
    recv(clientSocket, buffer, sizeof buffer - 1, 0);
    //assigning the "first" variable
    if(!strcmp(buffer,"1")){
    	first = 1;
    	cout<<1<<endl;
    }
    else if(!strcmp(buffer,"2")){
    	first = 0;
    	cout<< 0<<endl;
    }
    else{
    	cout<<"Error";
    	return 0;
    }
    while (cmdEXIT == 0)
    {
    	cout<<endl;
    	if(first == 0){
    		memset(&buffer[0], 0, sizeof(buffer));
    		//read from server
    		recvValue = recv(clientSocket, buffer, sizeof buffer - 1, 0);
    		cout<<buffer<<endl;
    		//print it
    		memset(&buffer[0], 0, sizeof(buffer));
    		//write to buffer
    		if(recvValue == 1){
    			cin>>buffer;
    			send(clientSocket,buffer,sizeof buffer - 1,0);
    			memset(&buffer[0], 0, sizeof(buffer));
			
    		}
    	}
    	if(first == 1){
    		memset(&buffer[0], 0, sizeof(buffer));
    		//write to buffer
    		if(recvValue == 1){
    			cin>>buffer;
    			send(clientSocket,buffer,sizeof buffer - 1,0);
    			memset(&buffer[0], 0, sizeof(buffer));
    		}
    		//read from server
    		recvValue = recv(clientSocket, buffer, sizeof buffer - 1, 0);
    		cout<<buffer<<endl;
    		//print it
		
    	}
    }

    return 0;
>>>>>>> d6fdb6c00963bac7dd2336df41ec533bf6c16dfc
}
