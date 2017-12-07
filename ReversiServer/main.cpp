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
	GameServer server("config.txt");
	server.start();
	return 1;
}
