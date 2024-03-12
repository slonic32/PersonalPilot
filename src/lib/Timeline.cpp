#include "Task.h"
#include "Timeline.h"
#include <vector>
#include <algorithm>

void Timeline::addTask(const Task &task)
{
    tasks.push_back(task);
}

void Timeline::removeTask(int id)
{
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task &task)
                               { return task.getId() == id; }),
                tasks.end());
}

std::vector<Task> Timeline::getAllTasks() const
{
    return tasks;
}
