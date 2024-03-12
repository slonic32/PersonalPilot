#include "lib/CLI.h"
#include "lib/Timeline.h"
#include "lib/FakeStorageAPI.h"
#include <iostream>

using namespace std;

int main()
{
    Timeline timeline;
    timeline = FakeStorageAPI::getExampleTimeline();
    CLI cli(timeline);
    cli.run();
    // save timeline
    //
    return 0;
}
