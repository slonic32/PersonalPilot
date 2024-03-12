#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

class Task
{
private:
    static int lastID;
    int id;
    std::string name;
    std::string description;
    bool status; // true if active, false otherwise
    int priority;
    std::chrono::system_clock::time_point deadline;
    // generate ID
    static int generateID();

public:
    // Constructor

    // full constructor will be implemented later
    //   Task(int id, std::string name, std::string description, bool status, int priority, std::chrono::system_clock::time_point deadline);
    // temporary version without description, priority and deadline
    Task(std::string name, bool status);
    // copy constructor
    Task(const Task &otherTask);

    // Getters and Setters
    int getId() const;

    std::string getName() const;

    std::string getDescription() const;

    bool getStatus() const;

    int getPriority() const;

    std::chrono::system_clock::time_point getDeadline() const;

    void setName(std::string name);

    void setDescription(std::string description);

    void setStatus(bool status);

    void setPriority(int priority);

    void setDeadline(std::chrono::system_clock::time_point deadline);

    static void setLastID(int _lastID);
};

#endif // TASK_H