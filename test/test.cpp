#define BOOST_TEST_MODULE HbpTests

#include <boost/test/unit_test.hpp>
#include "../include/humanratios.h"

BOOST_AUTO_TEST_SUITE(TestHumanRatios)

BOOST_AUTO_TEST_CASE(FailTest)
{
    BOOST_CHECK_EQUAL(5, 5);
}

BOOST_AUTO_TEST_CASE(PassTest)
{
    BOOST_CHECK_EQUAL(4, 4);
}

BOOST_AUTO_TEST_SUITE_END() // TestHumanRatios