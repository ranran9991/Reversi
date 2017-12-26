/*
 * Command.h
 *
 *  Created on: Dec 22, 2017
 *      Author: ranran9991
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Command{
public:
	virtual void execute(vector <string> args)=0;
	virtual ~Command();
};
#endif /* COMMAND_H_ */
