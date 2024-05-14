#include "Task.h"

int Task::lastID = 1; // Initialize static member

// Constructor
Task::Task(std::string name, std::string description, bool status, Priority priority, DateTime deadline)
{
    this->id = Task::generateID();
    this->name = name;
    this->description = description;
    this->status = status;
    this->priority = priority;
    this->deadline = deadline;
}

// copy constructor
Task::Task(const Task &otherTask)
{
    this->id = otherTask.id;
    this->name = otherTask.name;
    this->description = otherTask.description;
    this->status = otherTask.status;
    this->priority = otherTask.priority;
    this->deadline = otherTask.deadline;
}

// Getters and Setters
int Task::getId() const
{
    return id;
}

void Task::setId(const int newID)
{
    this->id = newID;
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

DateTime Task::getDeadline() const
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

void Task::setDeadline(DateTime deadline)
{
    this->deadline = deadline;
}

void Task::setLastID(int _lastID)
{
    lastID = _lastID;
}

int Task::getLastID()
{
    return lastID;
}

// generate ID
int Task::generateID()
{
    lastID++;
    return lastID;
}

void Task::setPriority(Priority priority)
{
    this->priority = priority;
}

Task::Priority Task::getPriority() const
{
    return priority;
}

// Overload << operator to print priority
std::ostream &operator<<(std::ostream &out, const Task::Priority &priority)
{
    out << "Priority: ";
    switch (priority)
    {
    case Task::Priority::High:
        out << "High";
        break;
    case Task::Priority::Medium:
        out << "Medium";
        break;
    case Task::Priority::Low:
        out << "Low";
        break;
    }
    out << "\n";
    return out;
}

// Overload >> operator to read priority
std::istream &operator>>(std::istream &in, Task::Priority &priority)
{
    char str;
    in >> str;
    switch (str)
    {
    case 'H':
        priority = Task::Priority::High;
        break;
    case 'M':
        priority = Task::Priority::Medium;
        break;
    case 'L':
        priority = Task::Priority::Low;
        break;
    }

    return in;
}

std::string to_string(Task::Priority priority)
{
    switch (priority)
    {
    case Task::Priority::High:
        return "High";
    case Task::Priority::Medium:
        return "Medium";
    case Task::Priority::Low:
        return "Low";
    default:
        return "Unknown";
    }
}

std::chrono::system_clock::time_point Task::stringToTime(const std::string &timeStr)
{
    std::istringstream ss(timeStr);
    std::tm tm = {};
    ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");
    std::time_t t = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(t);
}
