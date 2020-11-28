#ifndef __TASK_H
#define __TASK_H

#include <string>
#include <iostream>

class Task
{
    std::string taskName;
    std::string taskType;
    double executionTime;
    int priority;

    void copy(const std::string &, const std::string &, const double &, const int &);

public:
    Task() = default;
    Task(const std::string &, const std::string &, const double &, const int &);

    std::string getTaskName() const;
    std::string getTaskType() const;
    double getExecutionTime() const;
    int getPriority() const;

    bool operator==(const Task &) const;
    bool operator>(const Task &) const;

    friend std::ostream &operator<<(std::ostream &out, Task *_task);
};

#endif
