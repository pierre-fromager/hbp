
#ifndef TEST_HUMANRATIOS_FIXTURE_H
#define TEST_HUMANRATIOS_FIXTURE_H

#include "humanratios.h"
#include "f_common.h"

struct TestRatiosFixt : TestBaseFixt
{
    TestRatiosFixt(
        unsigned int gender,
        long double size,
        long double weight) : m_gender(gender),
                              m_size(size),
                              m_weight(weight)
    {
        BOOST_TEST_MESSAGE(m_setup);
        hr = new Human::Ratios(m_gender, m_size, m_weight);
    }
    ~TestRatiosFixt()
    {
        BOOST_TEST_MESSAGE(m_teardown);
        delete hr;
    }
    Human::Ratios *hr;
    unsigned int m_gender;
    long double m_size;
    long double m_weight;
};

struct MaleRatiosFixt : public TestRatiosFixt
{
    MaleRatiosFixt() : TestRatiosFixt(
                           Human::Genders::Id::MALE,
                           180,
                           80) {}
};

struct FemaleRatiosFixt : public TestRatiosFixt
{
    FemaleRatiosFixt() : TestRatiosFixt(
                             Human::Genders::Id::FEMALE,
                             165,
                             70) {}
};

#endif