#define BOOST_TEST_MODULE HbpTests

#include <boost/test/unit_test.hpp>
// #include "../include/humangenders.h"
// #include "../include/humanlimbs.h"
#include "../include/humanratios.h"

BOOST_AUTO_TEST_SUITE(TestHumanRatios)

struct TestHumanRatiosFixture
{
    TestHumanRatiosFixture() : i(0)
    {
        BOOST_TEST_MESSAGE("setup");
        hr = new Human::Ratios(Human::Genders::Id::MALE, 0, 0);
    }
    ~TestHumanRatiosFixture()
    {
        delete hr;
        BOOST_TEST_MESSAGE("teardown");
    }
    int i;
    Human::Ratios *hr;
};

BOOST_FIXTURE_TEST_CASE(THRF1, TestHumanRatiosFixture)
{
    BOOST_CHECK_EQUAL(i, 0);
    BOOST_CHECK_EQUAL(5, 5);
}

BOOST_FIXTURE_TEST_CASE(THRF2, TestHumanRatiosFixture)
{
    BOOST_CHECK_EQUAL(i, 0);
    BOOST_CHECK_EQUAL(4, 4);
}

BOOST_AUTO_TEST_CASE(TestHumanRatiosDummy)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END() // TestHumanRatios