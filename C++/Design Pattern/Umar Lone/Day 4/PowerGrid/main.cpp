#include "lampcontroller.h"


//state design Pattern
int main(int argc, char *argv[])
{
    LampController lamp;
    lamp.SetInitialState();
    lamp.switchon();
    lamp.switchon();
    lamp.switchon();
    lamp.switchoff();
    lamp.switchoff();
    lamp.switchoff();
    return 0;
}
