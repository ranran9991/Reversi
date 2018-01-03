/*
 * GameRoom.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: ron
 */

#include "GameRoom.h"

GameRoom::GameRoom() { }

GameRoom::GameRoom(string name, int id, bool wait) : name(name), id(id), wait(wait) { }

GameRoom::~GameRoom() { }
