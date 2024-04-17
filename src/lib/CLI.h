#ifndef CLI_H
#define CLI_H

#include "Timeline.h"

class CLI
{
private:
    Timeline timeline;
    bool flag;

    void printMainMenu();
    void handleAddTask();
    void handleRemoveTask();
    void handleGenerateReport();
    void handleEditTask();
    void handleMarkTaskComplete();
    void handleExit();

public:
    // constructor
    CLI(Timeline &_timeline);
    // methods
    void run();
};

#endif // CLI_H
