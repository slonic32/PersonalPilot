#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Task.h"
#include <vector>

class ReportGenerator
{
public:
    static void generateAllTasksReport(const std::vector<Task> &tasks);
};

#endif // REPORTGENERATOR_H
