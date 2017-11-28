/*
 * main.cpp
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#include <iostream>
#include "Game.h"
using namespace std;

int main(){
	Game game(new Board());
	game.Run();
}
