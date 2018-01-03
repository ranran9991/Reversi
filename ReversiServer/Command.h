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

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Command{
public:
	virtual bool execute(vector <string> args)=0;
	virtual ~Command();
};
#endif /* COMMAND_H_ */
