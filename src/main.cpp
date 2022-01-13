
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

void makeMePulse()
{
    Human::Body *me = new Human::Body();
    std::cout << "-- I pulse --" << std::endl;
    std::string stest = "emptymepls";
    unsigned int counter = 0;
    Human::Ratios *hr = new Human::Ratios(Human::Genders::Id::MALE, 180, 80);
    Ellipsoid *ell = new Ellipsoid();
    me->propCallback = [hr, &ell, &counter, &stest](DLinkedNode *n) mutable {
        const unsigned int id = n->getId();
        const ld hbdensvol = 1.01 * hr->getWeight(id);
        const ld size = hr->getSize(id);
        ell->setId(id);
        ell->setA(size);
        ell->setB(size / 2);
        ell->setC(size * 0.2);
        std::cout << "\t id : " << id << " label : "
                  << Human::Limbs::Labels.at((Human::Limbs::Id)id)
                  << " savol : " << hbdensvol
                  /*<< " ell A : " << ell->getA()
                  << " ell B : " << ell->getB()
                  << " ell C : " << ell->getC()*/
                  << " ell vol : " << ell->volume()
                  //<< " ell sur : " << ell->surface()
                  << std::endl;
        counter++;
        stest = "";
    };
    me->pulse();
    delete ell;
    delete hr;
    std::cout << "\t cb counter : " << counter << " stest : " << stest << std::endl;
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
    checkHumanRatios();
    makeMePulse();
    return 0;
}
