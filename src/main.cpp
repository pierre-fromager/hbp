
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

void makeMePulse(Human::Ratios *hr)
{
    Human::Body *me = new Human::Body();
    std::cout << "-- I pulse --" << std::endl;
    Ellipsoid *ell = new Ellipsoid();
    ld sumvol = 0;
    ld sumsur = 0;
    me->propCallback = [hr, &ell, &sumvol, &sumsur](DLinkedNode *n) mutable {
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
                  << std::setw(2)
                  << v << "cm³ " << s << "cm²" << std::endl;
        sumvol += v;
        sumsur += s;
    };
    me->pulse();
    delete ell;
    delete me;
    std::cout << "sum v : " << sumvol << "cm³" << std::endl;
    std::cout << "sum s : " << sumsur << "cm²" << std::endl;
    std::cout << "ratio s/v : " << sumsur / sumvol << std::endl;
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

int main(int argc, char **argv)
{
    (void)argc;
    char *prog = argv[0];
    if (prog)
    {
    }
    Human::Ratios *hr = new Human::Ratios(Human::Genders::Id::MALE, 180, 80);
    reportHumanRatios(hr);
    reportHumanRatios(hr, false);
    makeMePulse(hr);
    delete hr;
    return 0;
}
