// StorageAPI.cpp
#include "StorageAPI.h"
#include "Timeline.h"
#include "Task.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "Date.h"

Timeline StorageAPI::loadTimeline()
{
    Timeline timeline;

    int lastID;
    int id;
    std::string name;
    std::string description;
    bool status;
    std::string strDeadline1, strDeadline2;
    char strPriority;
    DateTime deadline;
    Task::Priority priority;

    // Open the file for reading
    std::ifstream inFile("timeline.txt");

    // Check if the file is successfully opened
    if (!inFile)
    {
        std::cout << "Failed to open the file." << std::endl;
        return timeline;
    }

    // Read each line from the file
    std::string line;
    while (getline(inFile, line))
    {
        std::stringstream ss(line);
        // Parse each line to extract the data
        if (!(ss >> id))
            break;
        if (!getline(inFile, name))
            break;
        if (!getline(inFile, description))
            break;
        if (!getline(inFile, line))
            break;
        std::stringstream ss1(line);
        if (!(ss1 >> status))
            break;
        if (!getline(inFile, line))
            break;
        std::stringstream ss2(line);
        if (!(ss2 >> strDeadline1 >> strDeadline2))
            break;
        if (!getline(inFile, line))
            break;
        std::stringstream ss3(line);
        if (!(ss3 >> strPriority))
            break;
        // Populate task
        switch (strPriority)
        {
        case 'H':
            priority = Task::Priority::High;
            break;
        case 'M':
            priority = Task::Priority::Medium;
            break;
        case 'L':
            priority = Task::Priority::Low;
            break;
        }
        deadline = DateTime::fromStr(strDeadline1 + " " + strDeadline2);

        Task task(name, description, status, priority, deadline);
        task.setId(id);

        // Add tasks to timeline
        timeline.addTask(task);
    }

    // set last ID
    getline(inFile, line);
    std::stringstream ss(line);
    if (ss >> lastID)
    {
        Task::setLastID(lastID);
    }

    // Close the file
    inFile.close();

    // Display the read data
    std::cout << "Data read from file:" << std::endl;

    return timeline;
}

void StorageAPI::saveTimeline(const Timeline &timeline)
{
    std::vector<Task> tasks = timeline.getAllTasks();
    int size = tasks.size();

    // Open a file stream for writing
    std::ofstream outFile("timeline.txt");

    // Check if the file is successfully opened
    if (!outFile)
    {
        std::cout << "Failed to save Timeline." << std::endl;
    }

    // Write each task to the file
    for (int i = 0; i < size; i++)
    {

        char strPriority;
        switch (tasks[i].getPriority())
        {
        case Task::Priority::High:
            strPriority = 'H';
            break;
        case Task::Priority::Medium:
            strPriority = 'M';
            break;
        case Task::Priority::Low:
            strPriority = 'L';
            break;
        }

        std::string strDate;
        strDate = DateTime::toStr(tasks[i].getDeadline());

        outFile
            << tasks[i].getId() << std::endl
            << tasks[i].getName() << std::endl
            << tasks[i].getDescription() << std::endl
            << tasks[i].getStatus() << std::endl
            << strDate << std::endl
            << strPriority << std::endl;
    }
    outFile << Task::getLastID() << std::endl;

    // Close the file stream
    outFile.close();

    std::cout << "Tasks saved to file." << std::endl;
}
