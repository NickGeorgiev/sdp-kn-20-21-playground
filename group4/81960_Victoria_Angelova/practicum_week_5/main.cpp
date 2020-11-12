#include <iostream>
#include "task.h"
#include "set.h"
#include "list.h"
#include "programmer.h"
#include "distributor.h"

int main()
{
    Set<Task *> tasks;

    Task *t1 = new Task("task1", "web", 2.5, 2);
    Task *t2 = new Task("task2", "web", 3, 3);
    Task *t3 = new Task("task3", "backend", 1, 3);
    Task *t4 = new Task("task4", "mobile", 5, 1);
    Task *t5 = new Task("task5", "mobile", 3, 3);

    tasks.add(t1);
    tasks.add(t2);
    tasks.add(t3);
    tasks.add(t4);
    tasks.add(t5);

    LList<Programmer *> Programmers;

    Programmer *p1 = new Programmer("Ivan Dobrev", "web", 10, "senior");
    Programmer *p2 = new Programmer("Teodor Atanasov", "mobile", 25, "junior");

    Programmers.add(p1);
    Programmers.add(p2);

    Distributor dis(tasks, Programmers);
   
    dis.assignTasks();

    dis.printTasksAndProgrammers();

    dis.printTasksLeft();

    return 0;
}

//g++ main.cpp task.cpp programmer.cpp distributor.cpp -o ...