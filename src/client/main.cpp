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
#include "Game.h"
using namespace std;

int main(){
	int mode;
	// print the menu
	cout <<
			"Welcome to Reversi!\n\n"
			"Choose an opponent type\n\n" <<
			"    1. A human local player\n" <<
			"    2. An AI player\n" <<
			"    3. A remote player\n\n";
	cin >> mode;
	cout << endl;
	// while an invalid input is received
	while (mode < 1 || mode > 3) {
		// print a message and the menu
		cout << "Invalid choice" << endl;
		cout <<
				"Choose an opponent type\n\n" <<
				"    1. A human local player\n" <<
				"    2. An AI player\n" <<
				"    3. A remote player\n\n";
		cin >> mode;
		cout << endl;
	}
	// create the game and run it
	Game game(new Board(), mode == 2, mode == 3);
	game.Run();
}
