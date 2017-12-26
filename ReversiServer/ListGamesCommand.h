/*
 * ListGamesCommand.h
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#ifndef LISTGAMESCOMMAND_H_
#define LISTGAMESCOMMAND_H_
#include "RoomCommand.h"

class ListGamesCommand : public RoomCommand {
public:
	void execute (vector <string> args);
	~ListGamesCommand();
};

#endif /* LISTGAMESCOMMAND_H_ */
