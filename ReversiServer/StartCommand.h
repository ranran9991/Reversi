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

#ifndef STARTCOMMAND_H_
#define STARTCOMMAND_H_
#include "RoomCommand.h"
class StartCommand : public RoomCommand {
public:
	bool execute(vector <string>);
	virtual ~StartCommand();
};

#endif /* STARTCOMMAND_H_ */
