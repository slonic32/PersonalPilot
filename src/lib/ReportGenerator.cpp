#include "Task.h"
#include "ReportGenerator.h"
#include <vector>
#include <iostream>

void ReportGenerator::generateAllTasksReport(const std::vector<Task> &tasks,
                                             const std::chrono::system_clock::time_point &startDate,
                                             const std::chrono::system_clock::time_point &endDate,
                                             bool activeTasksOnly)
{
    int number = 1;
    std::cout << "All Tasks Report:\n";
    for (const auto &task : tasks)
    {
        // Check if the task falls within the specified date range
        bool withinDateRange = task.getDeadline() >= startDate && task.getDeadline() <= endDate;

        // Check if the task matches the specified status criteria
        bool statusMatch = !activeTasksOnly || task.getStatus();

        // If both criteria are met, include the task in the report
        if (withinDateRange && statusMatch)
        {
            std::cout << "Task #" << number << "\n";
            number++;
            std::cout << "ID: " << task.getId() << "\n";
            std::cout << "Name: " << task.getName() << "\n";
            std::cout << "Priority: " << task.getPriority() << "\n";
            std::cout << "Deadline: " << std::chrono::system_clock::to_time_t(task.getDeadline()) << "\n";
            std::cout << "Status: " << (task.getStatus() ? "Active" : "Completed") << "\n\n";
        }
    }
}