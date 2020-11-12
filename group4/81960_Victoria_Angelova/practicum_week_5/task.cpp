#include "task.h"

void Task::copy(const std::string &_name, const std::string &_type, const double &_time, const int &_priority)
{
    taskName = _name;
    taskType = _type;
    executionTime = _time;
    priority = _priority;
}

Task::Task(const std::string &_name, const std::string &_type, const double &_time, const int &_priority)
{
    copy(_name, _type, _time, _priority);
}

std::string Task::getTaskName() const
{
    return taskName;
}

std::string Task::getTaskType() const
{
    return taskType;
}

double Task::getExecutionTime() const
{
    return executionTime;
}

int Task::getPriority() const
{
    return priority;
}

bool Task::operator==(const Task &_task) const
{
    return taskName == _task.getTaskName();
}

bool Task::operator>(const Task &_task) const
{
    return priority < _task.getPriority();
}

std::ostream &operator<<(std::ostream &out, Task *_task)
{
    out << std::endl;
    out << "Task: " << _task->getTaskName() << " " << _task->getTaskType() << " "
        << _task->getExecutionTime() << " " << _task->getPriority();

    return out;
}
