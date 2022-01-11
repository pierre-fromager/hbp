
#include <boost/test/unit_test.hpp>
#include <vector>
#include "test/fixtures/f_humanratios.h"

BOOST_AUTO_TEST_SUITE(TestSuiteHumanRatios)

namespace tt = boost::test_tools;

BOOST_FIXTURE_TEST_CASE(MaleGetter, MaleRatiosFixt)
{
    BOOST_CHECK_EQUAL(hr->getWeight(), 80);
    BOOST_CHECK_EQUAL(hr->getSize(), 180);
}

BOOST_FIXTURE_TEST_CASE(FemaleGetter, FemaleRatiosFixt)
{
    BOOST_CHECK_EQUAL(hr->getWeight(), 70);
    BOOST_CHECK_EQUAL(hr->getSize(), 165);
}

BOOST_FIXTURE_TEST_CASE(MaleWeight, MaleRatiosFixt)
{
    const std::vector<long double> expected = {
        44, 6.56, 2.56, 1.52, 0.48, 2.56, 1.52,
        0.48, 8.4, 3.76, 1.12, 8.4, 3.76, 1.12};
    int cpt = 0;
    for (const auto limbId : Human::Limbs::IdAll)
        BOOST_TEST(
            hr->getWeight(limbId) == expected[cpt++],
            tt::tolerance(0.15L));
}

BOOST_FIXTURE_TEST_CASE(MaleSize, MaleRatiosFixt)
{
    const std::vector<long double> expected = {
        54, 24.84, 30.96, 28.26, 18.72, 30.96, 28.26,
        18.72, 41.76, 44.46, 7.56, 41.76, 44.46, 7.56};
    int cpt = 0;
    for (const auto limbId : Human::Limbs::IdAll)
        BOOST_TEST(
            hr->getSize(limbId) == expected[cpt++],
            tt::tolerance(0.15L));
}

BOOST_FIXTURE_TEST_CASE(FemaleWeight, FemaleRatiosFixt)
{
    const std::vector<long double> expected = {
        37.1, 5.74, 2.03, 1.12, 0.35, 2.03, 1.12,
        0.35, 8.19, 3.71, 0.91, 8.19, 3.71, 0.91};
    int cpt = 0;
    for (const auto limbId : Human::Limbs::IdAll)
        BOOST_TEST(
            hr->getWeight(limbId) == expected[cpt++],
            tt::tolerance(0.15L));
}

BOOST_FIXTURE_TEST_CASE(FemaleSize, FemaleRatiosFixt)
{
    const std::vector<long double> expected = {
        49.5, 21.45, 31.845, 27.39, 17.16, 31.845, 27.39,
        17.16, 40.755, 42.24, 6.6, 40.755, 42.24, 6.6};
    int cpt = 0;
    for (const auto limbId : Human::Limbs::IdAll)
        BOOST_TEST(
            hr->getSize(limbId) == expected[cpt++],
            tt::tolerance(0.15L));
}

BOOST_AUTO_TEST_SUITE_END() // TestSuiteHumanRatios