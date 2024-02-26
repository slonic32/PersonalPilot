#include <string>
#include <iostream>
class Task
{
private:
    int id;
    std::string name;
    std::string description;
    std::string status;
    int priority;
    std::string deadline;

public:
    // Constructor
    Task(int id, std::string name, std::string description, std::string status, int priority, std::string deadline)
    {
        this->id = id;
        this->name = name;
        this->description = description;
        this->status = status;
        this->priority = priority;
        this->deadline = deadline;
    }

    // Getters and Setters
    int getId()
    {
        return id;
    }
    std::string getName()
    {
        return name;
    }
    std::string getDescription()
    {
        return description;
    }
    std::string getStatus()
    {
        return status;
    }
    int getPriority()
    {
        return priority;
    }
    std::string getDeadline()
    {
        return deadline;
    }

    void setId(int id)
    {
        this->id = id;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    void setDescription(std::string description)
    {
        this->description = description;
    }
    void setStatus(std::string status)
    {
        this->status = status;
    }
    void setPriority(int priority)
    {
        this->priority = priority;
    }
    void setDeadline(std::string deadline)
    {
        this->deadline = deadline;
    }
};

int main()
{
    // main in order to see how the class works
    Task task(1, "Task 1", "This is task 1", "In Progress", 1, "2024-02-26");
    std::cout << "Task ID: " << task.getId() << std::endl;
    std::cout << "Task Name: " << task.getName() << std::endl;
    std::cout << "Task Description: " << task.getDescription() << std::endl;
    std::cout << "Task Status: " << task.getStatus() << std::endl;
    std::cout << "Task Priority: " << task.getPriority() << std::endl;
    std::cout << "Task Deadline: " << task.getDeadline() << std::endl;
    task.setStatus("Completed");
    std::cout << "Updated Task Status: " << task.getStatus() << std::endl;

    return 0;
}
