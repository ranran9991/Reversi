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
