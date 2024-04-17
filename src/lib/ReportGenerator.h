#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include <vector>
#include "Task.h"

class ReportGenerator
{
public:
    // Function to display the report
    static void displayReport(const std::vector<Task> &tasks,
                              const std::chrono::system_clock::time_point &startDate,
                              const std::chrono::system_clock::time_point &endDate,
                              bool activeTasksOnly = false);
    static void displayReport(const std::vector<Task> &tasks,

                              bool activeTasksOnly = false);

    // Function to save the report to a file
    static void saveReportToFile(const std::vector<Task> &tasks,
                                 const std::chrono::system_clock::time_point &startDate,
                                 const std::chrono::system_clock::time_point &endDate,
                                 bool activeTasksOnly = false, const std::string &filename);
    static void saveReportToFile(const std::vector<Task> &tasks,

                                 bool activeTasksOnly = false, const std::string &filename);

private:
    // Function to generate the report content
    static void generateAllTasksReport(const std::vector<Task> &tasks,
                                       const std::chrono::system_clock::time_point &startDate,
                                       const std::chrono::system_clock::time_point &endDate,
                                       bool activeTasksOnly);
    static void generateAllTasksReport(const std::vector<Task> &tasks,
                                       bool activeTasksOnly);
    // Function to save the report content to a file
    static void saveReportContentToFile(const std::string &reportContent, const std::string &filename);
};

#endif // REPORTGENERATOR_H