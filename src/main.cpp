
#include <iostream>
#include <iomanip>
#include <stdexcept>
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
#define DASH "-"
#define HELP_OPTION DASH "h"
#define GENDER_OPTION DASH "g"
#define WEIGT_OPTION DASH "w"
#define SIZE_OPTION DASH "s"

typedef struct m_options_s
{
    unsigned int gender;
    long double size, weight;
} m_options_t;

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
                  << std::left << std::setw(3)
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
              << std::left << std::setw(3)
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

void show_usage(char **argv)
{
    std::cout << "Syntax: " << argv[0] << " -g <gender> -s <size> -w <weight>" << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<std::string> args(argv + 1, argv + argc);
    m_options_t opts = {0, 0, 0};
    short optcnt = 0;
    for (auto i = args.begin(); i != args.end(); ++i)
    {
        if (*i == HELP_OPTION)
        {
            show_usage(argv);
            return EXIT_SUCCESS;
        }
        else if (*i == GENDER_OPTION)
        {
            *i++;
            optcnt++;
            opts.gender = (unsigned int)stoul(*i, 0, 10);
        }
        else if (*i == SIZE_OPTION)
        {
            *i++;
            optcnt++;
            opts.size = stod(*i);
        }
        else if (*i == WEIGT_OPTION)
        {
            *i++;
            optcnt++;
            opts.weight = stod(*i);
        }
    }
    if (optcnt < 3)
    {
        show_usage(argv);
        return EXIT_FAILURE;
    }
    Human::Ratios *hr = new Human::Ratios(
        opts.gender,
        opts.size,
        opts.weight);
    reportHumanRatios(hr);
    reportHumanRatios(hr, false);
    pulse(hr);
    delete hr;
    return 0;
}
