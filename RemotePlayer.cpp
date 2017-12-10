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
	string buf;
	ifstream config;
	config.open(fileName);
	if(!config){
		//if file cant be opened
		throw "Can't open file, aborting";
	}
	config >> buf;
	config >> buf;
	config >> buf;
	strcpy(ip, buf.c_str());
	config >> buf; // buffer equals the port
	config >> buf;
	config >> buf;
	port = atoi(buf.c_str());
	//initializing socket 
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == -1) {
		//if socket can't be opened
		throw "Error opening socket";
	}
	struct in_addr address;
	if (!inet_aton(ip, &address)) {
		//if IP address cant be parsed
		throw "Can't parse IP address";
	}
	struct hostent *server;
	//if a server with this address can't be reached
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
		//if there was an error reading from the socket
		throw "Error reading from socket";
	}
	if (buffer[0] == '1') {
		//if this client is first
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
		//if the client is second 
		*first = false;
		this->first = true;
	}
}

void RemotePlayer::MakeMove() {
	int n;
	cout << "Current board:\n\n" << *board <<"\nWaiting for other player's move...\n\n";
	if (!first) {
		//making a string "X, Y" from the move on board X Y
		ostringstream os;
		os << board->GetLastMove().first << "," << board->GetLastMove().second << '\0';
		memset(buffer, '\0', BUFFER_SIZE_);
		strcpy(buffer, os.str().c_str());
		n = write(clientSocket, buffer, BUFFER_SIZE_);
		if (n == -1) {
			//Writing to socket wasn't successful
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
		//Reverting the string "X, Y" into two numbers, X and Y
		string str(buffer);
		int i = str.find(",");
		int x = atoi(str.substr(0,i).c_str());
		int y = atoi(str.substr(i+1).c_str());
		//making the move itself
		board->MakeMove(x, y, sign);
		cout << *board << endl; // print the board
		cout << sign << " played (" << x << "," << y << ")\n\n";
		lastMove = make_pair(x, y);
		return;
	}
	cout << "Other player had no possible moves. Play passes back to you.\n\n";
	lastMove = make_pair(0, 0);
}

RemotePlayer::~RemotePlayer() {
	//This destructor reads the last move of the game
	//this is not in the make move section because after one player finishes the game
	//he cant send his move to the other player in the main game loop.
	int n;
	if (!(lastMove == board->GetLastMove())) {
		//casting the string to a pair
		ostringstream os;
		os << board->GetLastMove().first << "," << board->GetLastMove().second << '\0';
		memset(buffer, '\0', BUFFER_SIZE_);
		strcpy(buffer, os.str().c_str());
		n = write(clientSocket, buffer, BUFFER_SIZE_);
		if (n == -1) {
			throw "Error writing move to socket";
		}
	}
	memset(buffer, '\0', BUFFER_SIZE_);
	strcpy(buffer, "End");
	n = write(clientSocket, buffer, BUFFER_SIZE_);
	if (n == -1) {
		throw "Error writing move to socket";
	}
	//close socket at the end of the lifetime of the player
	close(clientSocket);
}
