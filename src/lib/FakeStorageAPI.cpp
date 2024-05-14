// FakeStorageAPI.cpp
#include "FakeStorageAPI.h"
#include "Timeline.h"
#include "Task.h"
#include <string>
#include "Date.h"

Timeline FakeStorageAPI::getExampleTimeline()
{
    Timeline timeline;
    // Initialize task ID
    Task::setLastID(1);

    // Example tasks with details
    Task task1("Implement Task Class", "Implement Task Class", true, Task::Priority::High, DateTime::fromStr("2024-04-20 12:00:00"));
    Task task2("Implement Timeline Class", "Implement Timeline Class", true, Task::Priority::Medium, DateTime::fromStr("2024-04-22 10:00:00"));
    Task task3("Implement CLI Interface", "Implement CLI Interface", true, Task::Priority::Low, DateTime::fromStr("2024-04-24 15:00:00"));
    Task task4("Implement Reports", "Implement Reports", false, Task::Priority::High, DateTime::fromStr("2024-04-26 09:00:00"));
    Task task5("Get an excellent grade", "Get an excellent grade", false, Task::Priority::Medium, DateTime::fromStr("2024-04-28 14:00:00"));

    // Add tasks to timeline
    timeline.addTask(task1);
    timeline.addTask(task2);
    timeline.addTask(task3);
    timeline.addTask(task4);
    timeline.addTask(task5);

    return timeline;
}
