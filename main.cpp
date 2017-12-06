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
	int AL;
	// print the menu
	cout <<
			"Welcome to Reversi!\n\n"
			"Choose game mode\n\n" <<
			"    1. Human vs Computer\n" <<
			"    2. Two players\n\n";
	cin >> AL;
	cout << endl;
	// while an invalid input is received
	while (AL != 1 && AL != 2) {
		// print a message and the menu
		cout << "Invalid choice" << endl;
		cout <<
				"Choose game mode\n" <<
				"    1. Human vs Computer\n" <<
				"    2. Two players\n\n";
		cin >> AL;
		cout << endl;
	}
	// create the game and run it
	Game game(new Board(), AL == 1);
	game.Run();
}
