#include <iostream>
#include <fstream>
#include <vector>
#include "Task.h"
#include <string>

class ReportGenerator
{
public:
    // Function to display the report
    static void displayReport(const std::vector<Task> &tasks,
                              const std::chrono::system_clock::time_point &startDate,
                              const std::chrono::system_clock::time_point &endDate,
                              bool activeTasksOnly = false)
    {
        std::string reportContent = generateAllTasksReport(tasks, startDate, endDate, activeTasksOnly);
        std::cout << reportContent << "\n";
    }

    static void displayReport(const std::vector<Task> &tasks,
                              bool activeTasksOnly = false)
    {
        std::string reportContent = generateAllTasksReport(tasks, activeTasksOnly);
        std::cout << reportContent << "\n";
    }

    // Function to save the report to a file
    static void saveReportToFile(const std::vector<Task> &tasks,
                                 const std::chrono::system_clock::time_point &startDate,
                                 const std::chrono::system_clock::time_point &endDate,
                                 bool activeTasksOnly = false, const std::string &filename)
    {
        std::string reportContent = generateAllTasksReport(tasks, startDate, endDate, activeTasksOnly);
        saveReportContentToFile(reportContent, filename);
    }

    static void saveReportToFile(const std::vector<Task> &tasks,

                                 bool activeTasksOnly = false, const std::string &filename)
    {
        std::string reportContent = generateAllTasksReport(tasks, activeTasksOnly);
        saveReportContentToFile(reportContent, filename);
    }

private:
    // Function to generate the report content
    static std::string ReportGenerator::generateAllTasksReport(const std::vector<Task> &tasks,
                                                               const std::chrono::system_clock::time_point &startDate,
                                                               const std::chrono::system_clock::time_point &endDate,
                                                               bool activeTasksOnly)
    {
        std::string reportContent = "All Tasks Report:\n";
        int number = 1;
        for (const auto &task : tasks)
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
                reportContent += "Priority: " + to_string(task.getPriority()) + "\n";
                reportContent += "Deadline: " + std::to_string(std::chrono::system_clock::to_time_t(task.getDeadline())) + "\n";
                std::string taskStatus = (task.getStatus() ? "Active" : "Completed");
                reportContent += "Status: " + taskStatus + "\n\n";
            }
        }
    }

    static std::string ReportGenerator::generateAllTasksReport(const std::vector<Task> &tasks,
                                                               bool activeTasksOnly = false)
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
                reportContent += "Priority: " + to_string(task.getPriority()) + "\n";
                reportContent += "Deadline: " + std::to_string(std::chrono::system_clock::to_time_t(task.getDeadline())) + "\n";
                std::string taskStatus = (task.getStatus() ? "Active" : "Completed");
                reportContent += "Status: " + taskStatus + "\n\n";
            }
        }
    }

    // Function to save the report content to a file
    static void saveReportContentToFile(const std::string &reportContent, const std::string &filename)
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
};
