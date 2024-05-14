#include "lib/CLI.h"
#include "lib/Timeline.h"
#include "lib/StorageAPI.h"
#include "lib/FakeStorageAPI.h"
#include <iostream>

using namespace std;

int main()
{
    Timeline timeline;
    timeline = StorageAPI::loadTimeline();
    // timeline = FakeStorageAPI::getExampleTimeline();
    CLI cli(timeline);
    cli.run();

    return 0;
}
