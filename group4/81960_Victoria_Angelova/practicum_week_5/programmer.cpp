#include "programmer.h"

void Programmer::copy(const std::string &_name, const std::string &_spec,
                      const double &_hours, const std::string &_level)
{
    name = _name;
    specialization = _spec;
    hoursWorked = _hours;
    level = _level;
}

void Programmer::decreaseHours(const double &_hours)
{
    hoursWorked -= _hours;
}

Programmer::Programmer(const std::string &_name, const std::string &_spec,
                       const double &_hours, const std::string &_level)
{
    copy(_name, _spec, _hours, _level);
}

std::string Programmer::getName() const
{
    return name;
}

std::string Programmer::getSpecialization() const
{
    return specialization;
}

std::string Programmer::getLevel() const
{
    return level;
}
double Programmer::getHoursWorked() const
{
    return hoursWorked;
}

bool Programmer::canBeAssigned(Task *newTask) const
{
    if (getSpecialization() != newTask->getTaskType())
    {
        return false;
    }
    if (getLevel() == "junior" && newTask->getExecutionTime() * 4 <= getHoursWorked())
    {
        return true;
    }
    if (getLevel() == "middle" && newTask->getExecutionTime() * 2 <= getHoursWorked())
    {
        return true;
    }
    if (getLevel() == "senior" && newTask->getExecutionTime() <= getHoursWorked())
    {
        return true;
    }
    return false;
}

void Programmer::addTask(Task *newTask)
{
    assignedTasks.add(newTask);
    decreaseHours(newTask->getExecutionTime());
}

void Programmer::printTasks()
{
    assignedTasks.print();
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, Programmer *_programmer)
{
    out << std::endl;
    out << "Programmer: " << _programmer->getName() << " " << _programmer->getSpecialization() << " "
        << _programmer->getLevel() << " " << _programmer->getHoursWorked();

    return out;
}
