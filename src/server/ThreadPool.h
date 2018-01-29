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

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
private:
	queue<Task *> tasksQueue;
	pthread_t* threads;
	void executeTasks();
	bool stopped;
	pthread_mutex_t lock;

	static void *execute(void *arg);
public:
	ThreadPool(int threadsNum);
	void addTask(Task *task);
	void terminate();
	~ThreadPool();
};

#endif /* THREADPOOL_H_ */
