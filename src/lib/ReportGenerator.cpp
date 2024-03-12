#include "Task.h"
#include "ReportGenerator.h"
#include <vector>
#include <iostream>

void ReportGenerator::generateAllTasksReport(const std::vector<Task> &tasks)
{
    int number = 1;
    std::cout << "All Tasks Report:\n";
    for (const auto &task : tasks)
    {
        std::cout << "Task #" << number << "\n";
        number++;
        std::cout << "ID: " << task.getId() << "\n";
        std::cout << "Name: " << task.getName() << "\n";
        //     std::cout << "Description: " << task.getDescription() << "\n";
        std::cout << "Status: " << (task.getStatus() ? "Active" : "Completed") << "\n";
        //   std::cout << "Priority: " << task.getPriority() << "\n";
        //        std::cout << "Deadline: " << std::chrono::system_clock::to_time_t(task.getDeadline()) << "\n\n";
    }
}