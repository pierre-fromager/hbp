
#include <iostream>
#include "dlinkednode.h"
#include "ellipsoid.h"
#include "human.h"

void elltest()
{
    Ellipsoid *ell = new Ellipsoid(10.0f, 2.0f, 30.0f);
    char sbuf[30];
    sprintf(sbuf, "%.12Lf", ell->surface());
    char vbuf[30];
    sprintf(vbuf, "%.12Lf", ell->volume());
    char rbuf[30];
    sprintf(rbuf, "%.12Lf", ell->ratiosv());
    std::cout << "surface\t: " << sbuf << std::endl;
    std::cout << "volume\t: " << vbuf << std::endl;
    std::cout << "s/v\t: " << rbuf << std::endl;
    delete ell;
}

void makeMePulse()
{
    Human::Body *me = new Human::Body();
    std::cout << "-- I pulse --" << std::endl;
    me->pulse();
    delete me;
}

int main(int argc, char **argv)
{
    (void)argc;
    char *prog = argv[0];
    if (prog)
    {
    }
    makeMePulse();
    return 0;
}
