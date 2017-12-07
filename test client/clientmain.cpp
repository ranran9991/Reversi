#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
    int clientSocket,first,recvValue = 1;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
 

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    addr_size = sizeof serverAddr;

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
			first = 1;
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
		first = 0;
    	}
    }

    return 0;
}
