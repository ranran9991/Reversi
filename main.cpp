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
	int AL;
	cout <<
			"Welcome to Reversi!\n\n"
			"Choose game mode\n\n" <<
			"    1. Human vs Computer\n" <<
			"    2. Two players\n\n";
	cin >> AL;
	cout << endl;
	while (AL != 1 && AL != 2) {
		cout << "Invalid choice" << endl;
		cout <<
				"Choose game mode\n" <<
				"    1. Human vs Computer\n" <<
				"    2. Two players\n\n";
		cin >> AL;
		cout << endl;
	}
	Game game(new Board(), AL == 1);
	game.Run();
}
