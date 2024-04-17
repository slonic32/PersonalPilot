#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Task.h"
#include <vector>

class ReportGenerator
{
public:
    static void generateAllTasksReport(const std::vector<Task> &tasks,
                                       const std::chrono::system_clock::time_point &startDate,
                                       const std::chrono::system_clock::time_point &endDate,
                                       bool activeTasksOnly);
};

#endif // REPORTGENERATOR_H
