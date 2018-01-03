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
