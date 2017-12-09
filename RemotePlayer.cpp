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

#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(char* fileName, bool *first) :
		Player(), clientSocket(0) {
	//getting ip and port from file
	string buffer;
	ifstream config;
	config.open(fileName);
	if(!config){
		throw "Can't open file, aborting";
	}
	while (!config.eof()) {
	    config >> buffer;
	    if(buffer == "IP"){
	    	config>>buffer; // buffer = "="
		config>>buffer; //buffer equls the IP;
		ip = buffer.c_str();
	    }
	    if(buffer == "Port"){
	    	config>>buffer; // buffer = "="
	    	config>>buffer; // buffer equals the port
	    	port = atoi(buffer.c_str());
	    	return;
	    }
	}
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == -1) {
		throw "Error opening socket";
	}
	struct in_addr address;
	if (!inet_aton(ip, &address)) {
		throw "Can't parse IP address";
	}
	struct hostent *server;
	server = gethostbyaddr((const void*)&address, sizeof address, AF_INET);
	if (server == NULL) {
		throw "Host is unreachable";
	}
	// Create a structure for the server address
	struct sockaddr_in serverAddress;
	bzero((char*)&address, sizeof(address));
	serverAddress.sin_family = AF_INET;
	memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
	// htons converts values between host and network byte orders
	serverAddress.sin_port = htons(port);
	// Establish a connection with the TCP server
	if(connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		throw "Error connecting to server";
	}
	cout <<	"Connected to server" << endl;
	int n = read(clientSocket, buffer, BUFFER_SIZE_);
	if (n == -1) {
		throw "Error reading from socket";
	}
	if (buffer[0] == '1') {
		cout << "Waiting for other player to join...\n\n";
		memset(buffer, '\0', BUFFER_SIZE_);
		n = read(clientSocket, buffer, BUFFER_SIZE_);
		if (n == -1) {
			throw "Error reading from socket";
		}
		*first = true;
		this->first = false;
	}
	else {
		*first = false;
		this->first = true;
	}
}

void RemotePlayer::MakeMove() {
	int n;
	cout << "Current board:\n\n" << *board <<"\nWaiting for other player's move...\n\n";
	if (!first) {
		ostringstream os;
		os << board->GetLastMove().first << "," << board->GetLastMove().second << '\0';
		memset(buffer, '\0', BUFFER_SIZE_);
		strcpy(buffer, os.str().c_str());
		n = write(clientSocket, buffer, BUFFER_SIZE_);
		if (n == -1) {
			throw "Error writing move to socket";
		}
	}
	first = false;
	memset(buffer, '\0', BUFFER_SIZE_);
	n = read(clientSocket, buffer, BUFFER_SIZE_);
	if (n == -1) {
		throw "Error reading move from socket";
	}
	if (buffer[0] != '0') {
		board->MakeMove(buffer[0]-'0', buffer[2]-'0', sign);
		cout << *board << endl; // print the board
		cout << sign << " played (" << buffer[0] << "," << buffer[2] << ")\n\n";
	}
}

RemotePlayer::~RemotePlayer() { }
