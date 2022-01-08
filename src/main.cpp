
#include <iostream>
#include "dlinkednode.h"
#include "ellipsoid.h"

#include <sstream>
#include "model/ellipsoid.h"

#include "humanbody.h"

void elltest()
{
    Model::Ellipsoid em;
    const char sep = ';';
    std::string csvi = "0;10;50;20";
    std::replace(csvi.begin(), csvi.end(), sep, ' ');
    std::stringstream input;
    input << csvi;
    input >> em;
    Ellipsoid *ell = new Ellipsoid(em.id, em.a, em.b, em.c);
    const char *fmt = "%.12Lf";
    char sbuf[30];
    sprintf(sbuf, fmt, ell->surface());
    char vbuf[30];
    sprintf(vbuf, fmt, ell->volume());
    char rbuf[30];
    sprintf(rbuf, fmt, ell->ratiosv());
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
    elltest();
    makeMePulse();
    return 0;
}
