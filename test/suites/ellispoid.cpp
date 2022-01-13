
#include <boost/test/unit_test.hpp>
#include "test/fixtures/f_ellipsoid.h"

BOOST_AUTO_TEST_SUITE(TestSuiteEllipsoid)

namespace tt = boost::test_tools;

BOOST_FIXTURE_TEST_CASE(GetZeroes, EllipsoidZeroesFixt)
{
    const ld expectedZero = 0;
    BOOST_CHECK_EQUAL(ell->getId(), expectedZero);
    BOOST_CHECK_EQUAL(ell->volume(), expectedZero);
    BOOST_CHECK_EQUAL(ell->surface(), expectedZero);
    BOOST_CHECK_EQUAL(ell->ratiosv(), expectedZero);
}

BOOST_FIXTURE_TEST_CASE(GetOnes, EllipsoidIdOnesFixt)
{
    const ld expectedVol = 4.18;
    const ld expectedSurf = 12.56;
    const ld expectedRatio = 3;
    BOOST_CHECK_EQUAL(ell->getId(), 1);
    BOOST_TEST(ell->volume() == expectedVol, tt::tolerance(0.15L));
    BOOST_TEST(ell->surface() == expectedSurf, tt::tolerance(0.15L));
    BOOST_CHECK_EQUAL(ell->ratiosv(), expectedRatio);
}

BOOST_FIXTURE_TEST_CASE(GetTwos, EllipsoidIdTwosFixt)
{
    const ld expectedVol = 33.51;
    const ld expectedSurf = 50.26;
    const ld expectedRatio = 1.5;
    BOOST_CHECK_EQUAL(ell->getId(), 2);
    BOOST_TEST(ell->volume() == expectedVol, tt::tolerance(0.15L));
    BOOST_TEST(ell->surface() == expectedSurf, tt::tolerance(0.15L));
    BOOST_CHECK_EQUAL(ell->ratiosv(), expectedRatio);
}

BOOST_FIXTURE_TEST_CASE(GetSetABC, EllipsoidZeroesFixt)
{
    const ld expectedZero = 0;
    BOOST_CHECK_EQUAL(ell->getId(), expectedZero);
    BOOST_CHECK_EQUAL(ell->volume(), expectedZero);
    BOOST_CHECK_EQUAL(ell->surface(), expectedZero);
    BOOST_CHECK_EQUAL(ell->ratiosv(), expectedZero);
    const ld expected_a = 1;
    const ld expected_b = 2;
    const ld expected_c = 3;
    ell->setA(expected_a);
    ell->setB(expected_b);
    ell->setC(expected_c);

    BOOST_CHECK_EQUAL(ell->getA(), expected_a);
    BOOST_CHECK_EQUAL(ell->getB(), expected_b);
    BOOST_CHECK_EQUAL(ell->getC(), expected_c);
}

BOOST_AUTO_TEST_SUITE_END() // TestSuiteEllipsoid