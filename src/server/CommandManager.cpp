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

#include "CommandManager.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "StartCommand.h"

CommandManager::~CommandManager() {
	map<string, Command *>::iterator it;
	for(it = commandsMap.begin(); it != commandsMap.end(); it++){
		//delete it->second;
	}
}

CommandManager::CommandManager() {
	commandsMap["start"] = new StartCommand();
	commandsMap["list_games"] = new ListGamesCommand();
	commandsMap["join"] = new JoinCommand();
}

bool CommandManager::executeCommand(string command, vector<string> args) {
	Command* commandObj = commandsMap[command];
	return commandObj->execute(args);
}
