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
	int n;
	int option;
	bool sendCommands = true;
	string buf;
	string name;
	ostringstream os;
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
	cout << "Connected to server\n\n";
	while (sendCommands) {
		// print the remote player menu
		cout <<
				"Choose an option\n\n" <<
				"    1. Print list of existing games\n" <<
				"    2. Create a new game\n" <<
				"    3. Join an existing game\n\n";
		cin >> option; // scan the option
		cout << endl;
		// while an invalid input is received
		while (option < 1 || option > 3) {
			// print a message and the menu
			cout <<
					"Invalid option\n"
					"Choose an option\n\n" <<
					"    1. Print list of existing games\n" <<
					"    2. Create a new game\n" <<
					"    3. Join an existing game\n\n";
			cin >> option; // scan the option
			cout << endl;
		}
		os.str("");
		os.clear();
		switch (option){
		case 1: // print the list of existing games
			memset(buffer, '\0', BUFFER_SIZE_);
			strcpy(buffer, "list_games");
			// send command to server
			n = write(clientSocket, buffer, BUFFER_SIZE_);
			if (n == -1) {
				throw "Error writing to socket";
			}
			// read the list from the server
			n = read(clientSocket, buffer, BUFFER_SIZE_);
			if (n == -1) {
				throw "Error reading from socket";
			}
			// print the lists
			cout << buffer << endl;
			break;
		case 2: // create a new game
			cout << "Enter name of the new game: ";
			cin >> name; // scan the name for the game
			cout << endl;
			os << "start " << name << '\0';
			memset(buffer, '\0', BUFFER_SIZE_);
			strcpy(buffer, os.str().c_str());
			// send start command to server with the name
			n = write(clientSocket, buffer, BUFFER_SIZE_);
			if (n == -1) {
				throw "Error writing to socket";
			}
			// read whether the creation was successful or not
			n = read(clientSocket, buffer, BUFFER_SIZE_);
			if (n == -1) {
				throw "Error reading from socket";
			}
			if (buffer[0] == '0') { // if no such game exists
				cout << "Game created successfully\n\n"; // print a message
				sendCommands = false; // exit the loop afterwards
				cout << "Waiting for other player to join...\n\n";
				*first = true; // creator set to be first to play
				this->first = false; // should write to server in first move
				read(clientSocket, buffer, BUFFER_SIZE_); // wait for a message from server
			}
			// else print an error message
			else cout << "A game with the same name already exists\n\n";
			break;
		case 3:
			cout << "Enter name of the game you want to join: ";
			cin >> name; // scan the name for the game
			cout << endl;
			os << "join " << name << '\0';
			memset(buffer, '\0', BUFFER_SIZE_);
			strcpy(buffer, os.str().c_str());
			// send join command to server with the name
			n = write(clientSocket, buffer, BUFFER_SIZE_);
			if (n == -1) {
				throw "Error writing to socket";
			}
			memset(buffer, '\0', BUFFER_SIZE_);
			// read whether the joining was successful or not
			n = read(clientSocket, buffer, BUFFER_SIZE_);
			if (n == -1) {
				throw "Error reading from socket";
			}
			if (buffer[0] == '0') { // if this game exists
				cout << "Joined to game successfully\n\n";
				sendCommands = false; // exit the loop afterwards
				*first = false; // joiner set to be second to play
				this->first = true; // should not write to server in fisrt move
			}
			// else print an error message
			else cout << "No game with this name exists\n\n";
			break;
		default:
			cout << "this was not supposed to happen\n\n";
		}
	}
}

void RemotePlayer::MakeMove() {
	int n;
	cout << "Current board:\n\n" << *board <<"\nWaiting for other player's move...\n\n";
	/* this check is relevant only for the first move of the second player,
	 * because there is no message to write to the server
	 */
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
