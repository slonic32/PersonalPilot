#ifndef TIMELINE_H
#define TIMELINE_H

#include "Task.h"
#include <vector>

class Timeline
{
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task task);
    void removeTask(int id);
    std::vector<Task> getAllTasks() const;
};

#endif // TIMELINE_H
