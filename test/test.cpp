#define BOOST_TEST_MODULE HbpTests
#include <boost/test/unit_test.hpp>
#include <iomanip>
#include <vector>
//#include "testbasefixture.h"
#include "humanratios.h"

BOOST_AUTO_TEST_SUITE(TestHumanRatios)

namespace tt = boost::test_tools;

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

BOOST_FIXTURE_TEST_CASE(MaleNormalGetter, MaleRatiosFixt)
{
    BOOST_CHECK_EQUAL(hr->getWeight(), 80);
    BOOST_CHECK_EQUAL(hr->getSize(), 180);
}

BOOST_FIXTURE_TEST_CASE(FemaleNormalGetter, FemaleRatiosFixt)
{
    BOOST_CHECK_EQUAL(hr->getWeight(), 70);
    BOOST_CHECK_EQUAL(hr->getSize(), 165);
}

BOOST_FIXTURE_TEST_CASE(MaleNormalWeight, MaleRatiosFixt)
{
    const std::vector<long double> expected = {
        44, 6.56, 2.56, 1.52, 0.48, 2.56, 1.52,
        0.48, 8.4, 3.76, 1.12, 8.4, 3.76, 1.12};
    int cpt = 0;
    for (const auto limbId : Human::Limbs::IdAll)
        BOOST_TEST(hr->getWeight(limbId) == expected[cpt++], tt::tolerance(0.15L));
}

BOOST_AUTO_TEST_CASE(TestHumanRatiosDummy)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END() // TestHumanRatios