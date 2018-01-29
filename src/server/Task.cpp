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

#include "Task.h"

Task::Task(void * (*func)(void *arg), void *arg) : func(func), arg(arg) { }
void Task::execute(){
	func(arg);
}

Task::~Task() { }
