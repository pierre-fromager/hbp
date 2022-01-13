
#include <iostream>
#include <iomanip>

#include "dlinkednode.h"
#include "ellipsoid.h"
#include "humanratios.h"
#include "humanbody.h"
#include "dlinkednode.h"

#define TAB "\t"
#define STAR "*"
#define SPACE " "
#define CM "cm"
#define CM2 CM "²"
#define CM3 CM "³"
#define KG "kg"
#define WEIGHTS "weights"
#define SIZES "sizes"

void pulse(Human::Ratios *hr)
{
    std::cout << "-- On pulse --" << std::endl;
    Human::Body *me = new Human::Body();
    Ellipsoid *ell = new Ellipsoid();
    ld sumvol = 0;
    ld sumsur = 0;
    me->propCallback = [hr, ell, &sumvol, &sumsur](DLinkedNode *n) mutable {
        const unsigned int id = n->getId();
        const ld size = hr->getSize(id);
        ell->setId(id);
        ell->setA(size * 0.5);
        ell->setB(size * 0.5 * 0.5);
        ell->setC(size * 0.5 * 0.4);
        const ld v = ell->volume();
        const ld s = ell->surface();
        std::cout << std::setw(18) << std::left
                  << Human::Limbs::Labels.at((Human::Limbs::Id)id)
                  << std::setw(7) << std::left
                  << v << SPACE << CM3
                  << std::left << std::setw(4)
                  << SPACE << s << SPACE << CM2 << std::endl;
        sumvol += v;
        sumsur += s;
    };
    me->pulse();
    delete ell;
    delete me;
    std::cout << std::setw(18) << std::left << "SUM"
              << std::setw(7) << std::left
              << sumvol << SPACE << CM3
              << std::left << std::setw(4)
              << SPACE << sumsur << SPACE << CM2
              << std::endl;
    std::cout << std::setw(18) << std::left << "S/V"
              << sumsur / sumvol << std::endl;
}

void reportHumanRatios(Human::Ratios *hr, bool weighted = true)
{
    const std::string gender = (hr->getGender() == Human::Genders::Id::MALE)
                                   ? HUMAN_GENDER_LABEL_MALE
                                   : HUMAN_GENDER_LABEL_FEMALE;
    const std::string ssize = std::to_string((int)hr->getSize());
    const std::string sweight = std::to_string((int)hr->getWeight());
    const std::string rtype = weighted ? WEIGHTS : SIZES;
    const std::string title = gender + SPACE + ssize + "/" + sweight + SPACE + rtype;
    std::cout << STAR << SPACE << title << std::endl;
    char fmt_value[12];
    for (const auto limbId : Human::Limbs::IdAll)
    {
        const long double value = weighted ? hr->getWeight(limbId) : hr->getSize(limbId);
        sprintf(fmt_value, "%5.2Lf", value);
        const std::string unit = weighted ? KG : CM;
        std::cout << TAB
                  << std::setw(15) << std::left << Human::Limbs::Labels.at(limbId)
                  << std::setw(2)
                  << SPACE << ":" << SPACE
                  << fmt_value << SPACE << unit
                  << std::endl;
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    char *prog = argv[0];
    if (prog)
    {
    }
    Human::Ratios *hr = new Human::Ratios(Human::Genders::Id::FEMALE, 170, 60);
    reportHumanRatios(hr);
    reportHumanRatios(hr, false);
    pulse(hr);
    delete hr;
    return 0;
}
