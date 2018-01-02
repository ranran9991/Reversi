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
	GameServer server("serverconfig.txt");
	try{
	server.start();
	}
	catch(const char* temp){
		cout<<temp<<endl;
		server.stop();
	}
	return 0;
}
