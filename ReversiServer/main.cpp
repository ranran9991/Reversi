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
	try{
	GameServer server("serverconfig.txt");
	server.start();
	}
	catch(const char* temp){
		cout<<temp;
	}
	return 0;
}
