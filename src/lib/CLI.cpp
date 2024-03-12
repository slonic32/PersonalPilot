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
    std::cout << "3. Generate All Tasks Report\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void CLI::handleAddTask()
{
    std::string name;
    bool status = true;
    // Code for adding a task
    std::cout << "Enter Task Name:";
    std::cin >> name;
    Task newTask(name, status);
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

void CLI::handleGenerateReport()
{
    std::vector<Task> allTasks = timeline.getAllTasks();
    ReportGenerator::generateAllTasksReport(allTasks);
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
            handleGenerateReport();
            break;
        case 4:
            handleExit();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
