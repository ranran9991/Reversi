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

#ifndef REMOTEPLAYER_H_
#define REMOTEPLAYER_H_
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Player.h"
#define BUFFER_SIZE_ 1024

class RemotePlayer : public Player {
private:
	char ip[32];
	int port;
	int clientSocket;
	char buffer[BUFFER_SIZE_];
	bool first;
	pair<int, int> lastMove;
public:
	RemotePlayer(char* fileName, bool *first);
	void MakeMove();
	~RemotePlayer();
};

#endif /* REMOTEPLAYER_H_ */
