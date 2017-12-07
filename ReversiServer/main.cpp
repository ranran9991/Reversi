/*
 * main.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: ranran9991
 */


#include <iostream>
#include "GameServer.h"
using namespace std;

int main(){
	GameServer server(8000);
	server.start();
	return 1;
}
