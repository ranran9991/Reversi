/*
 * StartCommand.h
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
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
