// StorageAPI.h
#ifndef STORAGE_API_H
#define STORAGE_API_H

#include "Task.h"
#include "Timeline.h"

class StorageAPI
{
public:
    static Timeline loadTimeline();
    static void saveTimeline(const Timeline &);
};

#endif // STORAGE_API_H
