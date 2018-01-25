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

#ifndef TASK_H_
#define TASK_H_

class Task {
private:
	void *(*func)(void *arg);
	void *arg;
public:
	Task(void * (*func)(void *arg), void *arg);
	void execute();
	~Task();
};

#endif /* TASK_H_ */
