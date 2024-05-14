#include "CLI.h"
#include "ReportGenerator.h"
#include "Task.h"
#include "Timeline.h"
#include <iostream>
#include <string>
#include "Date.h"
#include "StorageAPI.h"

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

void CLI::printEditMenu()
{
    std::cout << "1. Edit Name\n";
    std::cout << "2. Edit Discription\n";
    std::cout << "3. Toggle Status\n";
    std::cout << "4. Edit Priority\n";
    std::cout << "5. Edit Deadline\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void CLI::handleAddTask()
{
    std::string name;
    std::string description;
    bool status = true;
    Task::Priority priority;
    DateTime deadline;

    std::cout << "Enter Task Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Task Description: ";
    std::getline(std::cin, description);

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
    std::string deadlineStr1, deadlineStr2;
    std::cin >> deadlineStr1 >> deadlineStr2;
    deadline = DateTime::fromStr(deadlineStr1 + " " + deadlineStr2); // Convert string to time_point

    Task newTask(name, description, status, priority, deadline);
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

        bool editFlag = true;
        std::string name;
        std::string description;
        char priorityInput;
        std::string deadlineStr1, deadlineStr2;

        int editChoice;
        while (editFlag)
        {
            printEditMenu();
            std::cin >> editChoice;
            std::cin.ignore();

            switch (editChoice)
            {
            case 1:

                std::cout << "Enter new Task Name: ";
                std::getline(std::cin, name);
                task->setName(name);
                std::cout << "Task details updated!\n";
                break;
            case 2:

                std::cout << "Enter new Task Description: ";
                std::getline(std::cin, description);
                task->setDescription(description);
                std::cout << "Task details updated!\n";
                break;
            case 3:
                if (task->getStatus())
                {
                    task->setStatus(false);
                    std::cout << "Task marked as complete!\n";
                }
                else
                {
                    task->setStatus(true);
                    std::cout << "Task marked as active!\n";
                }

                break;
            case 4:
                std::cout << "Enter Task Priority (H for High, M for Medium, L for Low): ";

                std::cin >> priorityInput;
                switch (priorityInput)
                {
                case 'H':
                case 'h':
                    task->setPriority(Task::Priority::High);
                    break;
                case 'M':
                case 'm':
                    task->setPriority(Task::Priority::Medium);
                    break;
                case 'L':
                case 'l':
                    task->setPriority(Task::Priority::Low);
                    break;
                default:
                    std::cout << "Invalid priority input. Setting priority to Low.\n";
                    task->setPriority(Task::Priority::Low);
                }
                break;
            case 5:
                std::cout << "Enter Task Deadline (YYYY-MM-DD HH:MM): ";

                std::cin >> deadlineStr1 >> deadlineStr2;
                task->setDeadline(DateTime::fromStr(deadlineStr1 + " " + deadlineStr2));
                break;
            case 6:
                editFlag = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
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

    DateTime startDate, endDate;
    bool activeTasksOnly = false; // Default to false for showing all tasks
    bool filterByDeadline = false;
    std::cout << "Do you want to filter by date range? (y/n): ";
    char choice;
    std::string startDateStr1 = "", endDateStr1 = "", startDateStr2 = "", endDateStr2 = "";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        filterByDeadline = true;
        std::cout << "Enter start date (YYYY-MM-DD HH:MM:SS): ";
        std::cin >> startDateStr1 >> startDateStr2;

        startDate = DateTime::fromStr(startDateStr1 + " " + startDateStr2);

        std::cout << startDateStr1 + " " + startDateStr2 << std::endl;
        std::cout << "Enter end date (YYYY-MM-DD HH:MM:SS): ";
        std::cin >> endDateStr1 >> endDateStr2;
        endDate = DateTime::fromStr(endDateStr1 + " " + endDateStr2);
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
        std::cout << std::endl;
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

    // save timeline

    StorageAPI::saveTimeline(timeline);
}
