
#include <iostream>
#include <iomanip>

#include "dlinkednode.h"
#include "ellipsoid.h"

#include <sstream>
#include "model/ellipsoid.h"

#include "humanratios.h"
#include "humanbody.h"

#include "dlinkednode.h"

#define TAB "\t"
#define STAR "*"
#define SPACE " "

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
    me->propCallback = [=](DLinkedNode *n) {
        std::cout << "\t callback id : " << n->getId() << std::endl;
    };
    me->pulse();
    delete me;
}

void reportHumanRatios(Human::Ratios *hr, bool weighted = true)
{
    const std::string gender = (hr->getGender() == Human::Genders::Id::MALE)
                                   ? HUMAN_GENDER_LABEL_MALE
                                   : HUMAN_GENDER_LABEL_FEMALE;
    const std::string ssize = std::to_string((int)hr->getSize());
    const std::string sweight = std::to_string((int)hr->getWeight());
    const std::string rtype = weighted ? "weights" : "sizes";
    const std::string title = gender + SPACE + ssize + "/" + sweight + SPACE + rtype;
    std::cout << STAR << SPACE << title << std::endl;
    for (const auto limbId : Human::Limbs::IdAll)
    {
        const long double value = weighted ? hr->getWeight(limbId) : hr->getSize(limbId);
        std::cout << TAB
                  << std::setw(15) << std::left << Human::Limbs::Labels.at(limbId)
                  << std::setw(2)
                  << " : " << value << std::endl;
    }
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
