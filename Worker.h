#ifndef __WORKER_H__
#define __WORKER_H__
#define WORK_ID 10

#include "Person.h"
#include <crtdbg.h> // TODO: remove before release


typedef enum { eCoffeeShop, eSecurity, eRestarunt, eStands, eNofTypes } Department;
static const char* typeTilte[eNofTypes] = { "CoffeeShop", "Security", "Restarunt", "Stands" };

typedef struct {
	Person*  person;//TODO: WATCH OUT
	int		WorkerId;
	Department department;
} Worker;

int initWorker(Worker* w, Person* p , Department dep);
int isValidInfoWorker(Department department);
void printWorker(const Worker* worker);
void freeWorker(Worker* worker);

#endif