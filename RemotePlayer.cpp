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
		if (board->GetLastMove().first != 0)
			os << board->GetLastMove().first << "," << board->GetLastMove().second << '\0';
		else os << "NoMove\0";
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
	if (strcmp(buffer, "NoMove")) {
		string str(buffer);
		int i = str.find(",");
		//cout << str.substr(0,i).c_str() << endl;
		int x = atoi(str.substr(0,i).c_str());
		int y = atoi(str.substr(i+1).c_str());
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
	int n;
	if (!(lastMove == board->GetLastMove())) {
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
	close(clientSocket);
}
