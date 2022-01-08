
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

void reportHumanRatios(Human::Ratios *hr, bool rmode = true)
{
    const std::string gender = (hr->getGender() == Human::Genders::Id::MALE)
                                   ? "Male"
                                   : "Female";
    const std::string ssize = std::to_string((int)hr->getSize());
    const std::string sweight = std::to_string((int)hr->getWeight());
    const std::string title = gender + " " + ssize + "/" + sweight;
    std::cout << "--" << title << "--" << std::endl;
    const std::string rtype = rmode ? "\t* Weight" : "\t* Size";
    std::cout << rtype << std::endl;
    const long double head_value = rmode ? hr->getWeight(Human::Limbs::Id::HEAD) : hr->getSize(Human::Limbs::Id::HEAD);
    std::cout << "\t\t- Head\t: " << std::to_string(head_value) << std::endl;
    const long double trunc_value = rmode ? hr->getWeight(Human::Limbs::Id::TRUNC) : hr->getSize(Human::Limbs::Id::TRUNC);
    std::cout << "\t\t- Trunc\t: " << std::to_string(trunc_value) << std::endl;
}

void checkHumanRatios()
{
    Human::Ratios *hr = new Human::Ratios(Human::Genders::Id::MALE, 180, 80);
    reportHumanRatios(hr);
    reportHumanRatios(hr, false);
    hr->setGender(Human::Genders::Id::FEMALE);
    hr->setSize(165);
    hr->setWeight(70);
    reportHumanRatios(hr);
    reportHumanRatios(hr, false);
    delete hr;
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
