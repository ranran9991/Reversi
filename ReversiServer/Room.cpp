/*
 * Room.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: ron
 */

#include "Room.h"

Room::Room() { }

Room::Room(string name, int id, bool wait) : name(name), id(id), wait(wait) { }

Room::~Room() { }
