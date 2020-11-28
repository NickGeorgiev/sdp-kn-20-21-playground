#ifndef __PROGRAMMER_H
#define __PROGRAMMER_H

#include <string>
#include "set.h"
#include "task.h"

class Programmer
{
    std::string name;
    std::string specialization;
    double hoursWorked;
    std::string level;
    Set<Task *> assignedTasks;

    void copy(const std::string &, const std::string &, const double &, const std::string &);
    void decreaseHours(const double &);

public:
    Programmer() = default;
    Programmer(const std::string &, const std::string &, const double &, const std::string &);

    std::string getName() const;
    std::string getSpecialization() const;
    std::string getLevel() const;
    double getHoursWorked() const;

    bool canBeAssigned(Task *) const;
    void addTask(Task *);

    void printTasks();

    friend std::ostream &operator<<(std::ostream &out, Programmer *_programmer);
};

#endif
