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

#include "GameRoom.h"

GameRoom::GameRoom() { }

GameRoom::GameRoom(string name, int id, bool wait) : name(name), id(id), wait(wait) { }

GameRoom::~GameRoom() { }
