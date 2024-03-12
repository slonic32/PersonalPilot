#include "Task.h"

// Constructor
Task::Task(int id, std::string name, std::string description, bool status, int priority, std::chrono::system_clock::time_point deadline)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->status = status;
    this->priority = priority;
    this->deadline = deadline;
}

// Getters and Setters
int Task::getId() const
{
    return id;
}
std::string Task::getName() const
{
    return name;
}
std::string Task::getDescription() const
{
    return description;
}
bool Task::getStatus() const
{
    return status;
}
int Task::getPriority() const
{
    return priority;
}
std::chrono::system_clock::time_point Task::getDeadline() const
{
    return deadline;
}
