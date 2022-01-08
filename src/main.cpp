
#include <iostream>
#include "dlinkednode.h"
#include "ellipsoid.h"

#include <sstream>
#include "model/ellipsoid.h"

#include "humanratios.h"
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

void checkHumanRatios()
{
    Human::Ratios *hr = new Human::Ratios(Human::Genders::Id::MALE, 185, 120);
    std::cout << "Weight\n"
              << std::endl;
    std::cout << "\tHead : " << hr->getWeight(Human::Limbs::Id::HEAD) << std::endl;
    std::cout << "\tTrunc : " << hr->getWeight(Human::Limbs::Id::TRUNC) << std::endl;
    std::cout << "Size\n"
              << std::endl;
    std::cout << "\tHead : " << hr->getSize(Human::Limbs::Id::HEAD) << std::endl;
    std::cout << "\tTrunc : " << hr->getSize(Human::Limbs::Id::TRUNC) << std::endl;
}

int main(int argc, char **argv)
{
    (void)argc;
    char *prog = argv[0];
    if (prog)
    {
    }
    elltest();
    checkHumanRatios();
    makeMePulse();
    return 0;
}
