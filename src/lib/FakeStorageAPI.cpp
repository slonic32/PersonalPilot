// FakeStorageAPI.cpp
#include "FakeStorageAPI.h"
#include "Timeline.h"
#include "Task.h"
#include <string>

Timeline FakeStorageAPI::getExampleTimeline()
{
    Timeline timeline;
    // Initialize task ID
    Task::setLastID(5); // Set to 5 since there are 5 example tasks below

    // Example tasks with details
    Task task1("Implement Task Class", true, Task::Priority::High, Task::stringToTime("2024-04-20T12:00:00"));
    Task task2("Implement Timeline Class", true, Task::Priority::Medium, Task::stringToTime("2024-04-22T10:00:00"));
    Task task3("Implement CLI Interface", true, Task::Priority::Low, Task::stringToTime("2024-04-24T15:00:00"));
    Task task4("Implement Reports", false, Task::Priority::High, Task::stringToTime("2024-04-26T09:00:00"));
    Task task5("Get an excellent grade", false, Task::Priority::Medium, Task::stringToTime("2024-04-28T14:00:00"));

    // Add tasks to timeline
    timeline.addTask(task1);
    timeline.addTask(task2);
    timeline.addTask(task3);
    timeline.addTask(task4);
    timeline.addTask(task5);

    return timeline;
}
