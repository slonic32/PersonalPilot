#include "Task.h"

// Constructor
Task::Task(std::string name, bool status)
{
    this->id = Task::generateID();
    this->name = name;
    //  this->description = description;
    this->status = status;
    //  this->priority = priority;
    //  this->deadline = deadline;
}
// copy constructor
Task::Task(Task &otherTask)
{
    this->id = otherTask.id;
    this->name = otherTask.name;
    //  this->description = otherTask.description;
    this->status = otherTask.status;
    //  this->priority = otherTask.priority;
    //  this->deadline = otherTask.deadline;
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

void Task::setName(std::string name)
{
    this->name = name;
}
void Task::setDescription(std::string description)
{
    this->description = description;
}
void Task::setStatus(bool status)
{
    this->status = status;
}
void Task::setPriority(int priority)
{
    this->priority = priority;
}
void Task::setDeadline(std::chrono::system_clock::time_point deadline)
{
    this->deadline = deadline;
}

void Task::setLastID(int _lastID)
{
    lastID = _lastID;
}

// generate ID
int Task::generateID()
{
    lastID++;
    return lastID;
}