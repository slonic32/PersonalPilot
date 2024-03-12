#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

class Task
{
private:
    int id;
    std::string name;
    std::string description;
    bool status; // true if active, false otherwise
    int priority;
    std::chrono::system_clock::time_point deadline;

public:
    // Constructor
    Task(int id, std::string name, std::string description, bool status, int priority, std::chrono::system_clock::time_point deadline);

    // Getters and Setters
    int getId() const;

    std::string getName() const;

    std::string getDescription() const;

    bool getStatus() const;

    int getPriority() const;

    std::chrono::system_clock::time_point getDeadline() const;
};

#endif // TASK_H