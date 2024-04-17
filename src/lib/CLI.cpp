#include "CLI.h"
#include "ReportGenerator.h"
#include "Task.h"
#include "Timeline.h"
#include <iostream>
#include <string>

// constructor
CLI::CLI(Timeline &_timeline) : flag(true)
{
    timeline = _timeline;
}

// methods

void CLI::printMainMenu()
{
    std::cout << "=== PersonalPilot - Task Management System ===\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Edit Task\n";
    std::cout << "4. Mark Task as Complete\n";
    std::cout << "5. Generate Tasks Report\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void CLI::handleAddTask()
{
    std::string name;
    bool status = true;
    Task::Priority priority;
    std::chrono::system_clock::time_point deadline;

    std::cout << "Enter Task Name: ";
    std::cin >> name;

    /*// Prompt for task status (active or completed)
    char statusInput;
    std::cout << "Is the task active? (y/n): ";
    std::cin >> statusInput;
    status = (statusInput == 'y' || statusInput == 'Y');*/

    // Prompt for task priority
    std::cout << "Enter Task Priority (H for High, M for Medium, L for Low): ";
    char priorityInput;
    std::cin >> priorityInput;
    switch (priorityInput)
    {
    case 'H':
    case 'h':
        priority = Task::Priority::High;
        break;
    case 'M':
    case 'm':
        priority = Task::Priority::Medium;
        break;
    case 'L':
    case 'l':
        priority = Task::Priority::Low;
        break;
    default:
        std::cout << "Invalid priority input. Setting priority to Low.\n";
        priority = Task::Priority::Low;
    }

    // Prompt for task deadline
    std::cout << "Enter Task Deadline (YYYY-MM-DD HH:MM): ";
    std::string deadlineStr;
    std::cin >> deadlineStr;
    deadline = Task::stringToTime(deadlineStr); // Convert string to time_point (you need to implement this function)

    Task newTask(name, status, priority, deadline);
    timeline.addTask(newTask);
    std::cout << "Task added!\n";
}

void CLI::handleRemoveTask()
{
    int id;
    // Code for removig a task
    std::cout << "Enter Task ID:";
    std::cin >> id;
    timeline.removeTask(id);
    std::cout << "Task removed!\n";
}

void CLI::handleEditTask()
{
    int id;
    std::cout << "Enter Task ID to edit: ";
    std::cin >> id;
    Task *task = timeline.findTask(id);
    if (task != nullptr)
    {
        std::string name;
        std::cout << "Enter new Task Name: ";
        std::cin >> name;
        task->setName(name);
        std::cout << "Task details updated!\n";
    }
    else
    {
        std::cout << "Task not found!\n";
    }
}

void CLI::handleMarkTaskComplete()
{
    int id;
    std::cout << "Enter Task ID to mark as complete: ";
    std::cin >> id;
    Task *task = timeline.findTask(id);
    if (task != nullptr)
    {
        task->setStatus(false);
        std::cout << "Task marked as complete!\n";
    }
    else
    {
        std::cout << "Task not found!\n";
    }
}

void CLI::handleGenerateReport()
{
    std::string filename;

    bool saveToFile = false;
    char saveToFileInput;
    std::cout << "Save to file? ";
    std::cin >> saveToFileInput;
    saveToFile = (saveToFileInput == 'y' || saveToFileInput == 'Y');

    if (saveToFile)
    {
        std::cout << "Enter filename to save the report: ";
        std::cin >> filename;
    }

    std::chrono::system_clock::time_point startDate, endDate;
    bool activeTasksOnly = false; // Default to false for saving all tasks
    bool filterByDeadline = false;
    std::cout << "Do you want to filter by date range? (y/n): ";
    char choice;
    std::string startDateStr = "", endDateStr = "";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        filterByDeadline = true;
        std::cout << "Enter start date (YYYY-MM-DD HH:MM:SS): ";
        std::cin >> startDateStr;
        startDate = Task::stringToTime(startDateStr);
        std::cout << "Enter end date (YYYY-MM-DD HH:MM:SS): ";
        std::cin >> endDateStr;
        endDate = Task::stringToTime(endDateStr);
    }

    std::cout << "Do you want to filter by active tasks only? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        activeTasksOnly = true;
    }

    if (saveToFile)
    {
        if (filterByDeadline)
        {
            ReportGenerator::saveReportToFile(timeline.getAllTasks(), startDate, endDate, activeTasksOnly, filename);
        }
        else
        {
            ReportGenerator::saveReportToFile(timeline.getAllTasks(), activeTasksOnly, filename);
        }
    }
    else
    {
        if (filterByDeadline)
        {
            ReportGenerator::displayReport(timeline.getAllTasks(), startDate, endDate, activeTasksOnly);
        }
        else
        {
            ReportGenerator::displayReport(timeline.getAllTasks(), activeTasksOnly);
        }
    }
}

void CLI::handleExit()
{
    std::cout << "Exiting PersonalPilot. Goodbye!\n";
    flag = false;
}

void CLI::run()
{
    int choice;
    while (flag)
    {
        printMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            handleAddTask();
            break;
        case 2:
            handleRemoveTask();
            break;
        case 3:
            handleEditTask();
            break;
        case 4:
            handleMarkTaskComplete();
            break;
        case 5:
            handleGenerateReport();
            break;
        case 6:
            handleExit();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
