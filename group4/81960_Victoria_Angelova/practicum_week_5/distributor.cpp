#include "distributor.h"

bool Distributor::assignTask(Task *task, Programmer *programmer)
{
    if (programmer->canBeAssigned(task))
    {
        programmer->addTask(task);
        tasksToBeAssigned.remove(task);
        return true;
    }
    return false;
}

/*void Distributor::addTask(Task* newTask) {
    tasksToBeAssigned.add(newTask);
}*/

/*void Distributor::addProgrammer(Programmer* newProgrammer) {
    programmers.add(newProgrammer);
}*/

void Distributor::assignTasks()
{
    for (Task *t : tasksToBeAssigned)
    {
        for (Programmer *p : programmers)
        {
            if (assignTask(t, p))
            {
                break;
            }
        }
    }
}

void Distributor::printTasksAndProgrammers()
{
    for (Programmer *p : programmers)
    {
        std::cout << p;
        p->printTasks();
    }
}

void Distributor::printTasksLeft() {
    std::cout<<std::endl<<"Tasks left: ";
    tasksToBeAssigned.print();
}
