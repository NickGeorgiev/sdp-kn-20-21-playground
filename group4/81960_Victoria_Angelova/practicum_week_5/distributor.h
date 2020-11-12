#ifndef __DISTRIBUTOR_H
#define __DISTRIBUTOR_H

#include "set.h"
#include "list.h"
#include "task.h"
#include "programmer.h"

class Distributor
{
    Set<Task *> tasksToBeAssigned;
    LList<Programmer *> programmers;

    bool assignTask(Task *, Programmer *);

public:
    Distributor(const Set<Task *> &_tasks, const LList<Programmer *> &_programmers) : tasksToBeAssigned{_tasks}, programmers{_programmers} {}
    ~Distributor() = default;

    //void addTask (Task*);
    //void addProgrammer (Programmer*);

    void assignTasks();

    void printTasksAndProgrammers();
    void printTasksLeft();
};

#endif