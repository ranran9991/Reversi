/*
 * CommandManager.h
 *
 *  Created on: Dec 23, 2017
 *      Author: ranran9991
 */

#ifndef COMMANDMANAGER_H_
#define COMMANDMANAGER_H_
#include <map>
#include "Command.h"
class CommandManager {
public:
	map <string, Command*> commandsMap;
	CommandManager();
	bool executeCommand(string command, vector <string> args);
	~CommandManager();
};

#endif /* COMMANDMANAGER_H_ */
