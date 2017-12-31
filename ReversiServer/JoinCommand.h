/*
 * JoinCommand.h
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_
#include "RoomCommand.h"
#include <pthread.h>
class JoinCommand : public RoomCommand {
public:
	void execute(vector <string>);
	~JoinCommand();
private:
	pthread_mutex_t lock;

};

#endif /* JOINCOMMAND_H_ */
