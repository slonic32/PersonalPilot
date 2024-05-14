#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "Date.h"

class Task
{
public:
    enum class Priority
    {
        High,
        Medium,
        Low
    };

private:
    static int lastID;
    int id;
    std::string name;
    std::string description;
    bool status; // true if active, false otherwise
    DateTime deadline;
    // generate ID
    static int generateID();

    // Add a member variable to store task priority

    Priority priority;

public:
    // Constructor

    Task(std::string name, std::string description, bool status, Priority priority, DateTime deadline);
    // copy constructor
    Task(const Task &otherTask);

    // Getters and Setters
    int getId() const;
    void setId(const int);

    std::string getName() const;

    std::string getDescription() const;

    bool getStatus() const;

    void setName(std::string name);

    void setDescription(std::string description);

    void setStatus(bool status);

    static void setLastID(int _lastID);
    static int getLastID();

    void setPriority(Priority priority);
    Priority getPriority() const;

    // Overload << operator to print priority
    friend std::ostream &operator<<(std::ostream &os, const Priority &priority);
    // Overload >> operator to read priority
    friend std::istream &operator>>(std::istream &os, Priority &priority);

    void setDeadline(DateTime deadline);
    DateTime getDeadline() const;

    friend std::string to_string(Priority priority);

    static std::chrono::system_clock::time_point stringToTime(const std::string &timeStr);
};

#endif // TASK_H