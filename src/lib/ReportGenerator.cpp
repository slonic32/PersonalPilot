#include <iostream>
#include <fstream>
#include <vector>
#include "Task.h"
#include <string>
#include "ReportGenerator.h"
#include "Date.h"

// Function to display the report
void ReportGenerator::displayReport(const std::vector<Task> &tasks,
                                    const DateTime &startDate,
                                    const DateTime &endDate,
                                    bool activeTasksOnly)
{
    std::string reportContent = ReportGenerator::generateAllTasksReport(tasks, startDate, endDate, activeTasksOnly);
    std::cout << reportContent << "\n";
}

void ReportGenerator::displayReport(const std::vector<Task> &tasks,
                                    bool activeTasksOnly)
{
    std::string reportContent = ReportGenerator::generateAllTasksReport(tasks, activeTasksOnly);
    std::cout << reportContent << "\n";
}

// Function to save the report to a file
void ReportGenerator::saveReportToFile(const std::vector<Task> &tasks,
                                       const DateTime &startDate,
                                       const DateTime &endDate,
                                       bool activeTasksOnly, const std::string &filename)
{
    std::string reportContent = ReportGenerator::generateAllTasksReport(tasks, startDate, endDate, activeTasksOnly);
    ReportGenerator::saveReportContentToFile(reportContent, filename);
}

void ReportGenerator::saveReportToFile(const std::vector<Task> &tasks,

                                       bool activeTasksOnly, const std::string &filename)
{
    std::string reportContent = ReportGenerator::generateAllTasksReport(tasks, activeTasksOnly);
    ReportGenerator::saveReportContentToFile(reportContent, filename);
}

// Function to generate the report content
std::string ReportGenerator::generateAllTasksReport(const std::vector<Task> &tasks,
                                                    const DateTime &startDate,
                                                    const DateTime &endDate,
                                                    bool activeTasksOnly)
{
    std::string reportContent = "All Tasks Report:\n";
    int number = 1;
    for (const Task &task : tasks)
    {
        // Check if the task falls within the specified date range
        bool withinDateRange = task.getDeadline() >= startDate && task.getDeadline() <= endDate;

        // Check if the task matches the specified status criteria
        bool statusMatch = !activeTasksOnly || task.getStatus();

        // If both criteria are met, include the task in the report
        if (withinDateRange && statusMatch)
        {
            reportContent += "Task #" + std::to_string(number) + "\n";
            number++;
            reportContent += "ID: " + std::to_string(task.getId()) + "\n";
            reportContent += "Name: " + task.getName() + "\n";
            reportContent += "Description: " + task.getDescription() + "\n";
            reportContent += "Priority: " + to_string(task.getPriority()) + "\n";
            reportContent += "Deadline: " + DateTime::toStr(task.getDeadline()) + "\n";
            std::string taskStatus = (task.getStatus() ? "Active" : "Completed");
            reportContent += "Status: " + taskStatus + "\n\n";
        }
    }
    return reportContent;
}

std::string ReportGenerator::generateAllTasksReport(const std::vector<Task> &tasks,
                                                    bool activeTasksOnly)
{
    std::string reportContent = "All Tasks Report:\n";
    int number = 1;
    for (const auto &task : tasks)
    {
        // Check if the task matches the specified status criteria
        bool statusMatch = !activeTasksOnly || task.getStatus();

        // If both criteria are met, include the task in the report
        if (statusMatch)
        {
            reportContent += "Task #" + std::to_string(number) + "\n";
            number++;
            reportContent += "ID: " + std::to_string(task.getId()) + "\n";
            reportContent += "Name: " + task.getName() + "\n";
            reportContent += "Description: " + task.getDescription() + "\n";
            reportContent += "Priority: " + to_string(task.getPriority()) + "\n";
            reportContent += "Deadline: " + DateTime::toStr(task.getDeadline()) + "\n";
            std::string taskStatus = (task.getStatus() ? "Active" : "Completed");
            reportContent += "Status: " + taskStatus + "\n\n";
        }
    }
    return reportContent;
}

// Function to save the report content to a file
void ReportGenerator::saveReportContentToFile(const std::string &reportContent, const std::string &filename)
{
    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << reportContent;
        outputFile.close();
        std::cout << "Report saved to " << filename << "\n";
    }
    else
    {
        std::cerr << "Unable to open file " << filename << " for writing\n";
    }
}
