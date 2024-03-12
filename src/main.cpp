#include "lib/CLI.h"
#include "Timeline.h"
#include <iostream>

using namespace std;

int main()
{
    Timeline timeline;
    CLI cli(timeline);
    cli.run();
    return 0;
}
