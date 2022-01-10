#define BOOST_TEST_MODULE HbpTests

#include <boost/test/unit_test.hpp>
#include <iomanip>
//#include "testbasefixture.h"
#include "humanratios.h"

BOOST_AUTO_TEST_SUITE(TestHumanRatios)

struct TestBaseFixt
{
    const std::string m_setup = "setup";
    const std::string m_teardown = "teardown";
};

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

BOOST_FIXTURE_TEST_CASE(MaleNormal, MaleRatiosFixt)
{
    for (const auto limbId : Human::Limbs::IdAll)
    {
        const long double value = hr->getWeight(limbId);
        std::cout << std::setw(15) << std::left
                  << Human::Limbs::Labels.at(limbId)
                  << std::setw(2)
                  << " : " << value << std::endl;
    }

    BOOST_CHECK_EQUAL(hr->getWeight(), 80);
    BOOST_CHECK_EQUAL(hr->getSize(), 180);
}

BOOST_FIXTURE_TEST_CASE(FemaleNormal, FemaleRatiosFixt)
{
    BOOST_CHECK_EQUAL(hr->getWeight(), 70);
    BOOST_CHECK_EQUAL(hr->getSize(), 165);
}

BOOST_AUTO_TEST_CASE(TestHumanRatiosDummy)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END() // TestHumanRatios