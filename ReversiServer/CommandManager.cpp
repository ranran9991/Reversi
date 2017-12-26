/*
 * CommandManager.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: ranran9991
 */

#include "CommandManager.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "StartCommand.h"

CommandManager::~CommandManager() {
	map<string, Command *>::iterator it;
	for(it = commandsMap.begin(); it != commandsMap.end(); it++){
		delete it->second;
	}
}

CommandManager::CommandManager() {
	commandsMap["start"] = new StartCommand();
	commandsMap["list_games"] = new ListGamesCommand();
	commandsMap["join"] = new JoinCommand();
}

void CommandManager::executeCommand(string command, vector<string> args) {
	Command* commandObj = commandsMap[command];
	commandObj->execute(args);
}
