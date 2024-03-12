// FakeStorageAPI.cpp
#include "FakeStorageAPI.h"
#include "Timeline.h"
#include "Task.h"
#include "string"

Timeline FakeStorageAPI::getExampleTimeline()
{
    Timeline timeline;
    // initialize taskID
    Task::setLastID(1);

    // Example tasks
    Task task1("Implement Task Class", true);
    Task task2("Implement Timeline Class", true);
    Task task3("Implement CLI Interface", true);
    Task task4("Implement Reports", true);
    Task task5("Get an excellent grade", true);

    // Add tasks to timeline
    timeline.addTask(task1);
    timeline.addTask(task2);
    timeline.addTask(task3);
    timeline.addTask(task4);
    timeline.addTask(task5);

    return timeline;
}
