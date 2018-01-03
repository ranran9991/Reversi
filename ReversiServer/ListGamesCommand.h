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

#ifndef LISTGAMESCOMMAND_H_
#define LISTGAMESCOMMAND_H_
#include "RoomCommand.h"

class ListGamesCommand : public RoomCommand {
public:
	bool execute (vector <string> args);
	~ListGamesCommand();
};

#endif /* LISTGAMESCOMMAND_H_ */
