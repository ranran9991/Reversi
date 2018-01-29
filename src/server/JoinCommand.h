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

#ifndef JOINCOMMAND_H_
#define JOINCOMMAND_H_
#include "RoomCommand.h"
#include <pthread.h>
class JoinCommand : public RoomCommand {
public:
	bool execute(vector <string>);
	~JoinCommand();
private:
	pthread_mutex_t lock;

};

#endif /* JOINCOMMAND_H_ */
