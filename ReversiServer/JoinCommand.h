/*
 * JoinCommand.h
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_
#include "RoomCommand.h"
class JoinCommand : public RoomCommand {
public:
	void execute(vector <string>);
	~JoinCommand();
};

#endif /* JOINCOMMAND_H_ */
