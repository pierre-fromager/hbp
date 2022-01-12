
#include <boost/test/unit_test.hpp>
#include "test/fixtures/model/f_ellipsoid.h"

BOOST_AUTO_TEST_SUITE(TestSuiteModelEllipsoid)

BOOST_FIXTURE_TEST_CASE(InCsvZeroes, ModelEllipsoidZeroesFixt)
{
    BOOST_CHECK_EQUAL(m_em.id, 0);
    BOOST_CHECK_EQUAL(m_em.a, 0);
    BOOST_CHECK_EQUAL(m_em.b, 0);
    BOOST_CHECK_EQUAL(m_em.c, 0);
}

BOOST_FIXTURE_TEST_CASE(InCsvOnes, ModelEllipsoidOnesFixt)
{
    BOOST_CHECK_EQUAL(m_em.id, 1);
    BOOST_CHECK_EQUAL(m_em.a, 1);
    BOOST_CHECK_EQUAL(m_em.b, 1);
    BOOST_CHECK_EQUAL(m_em.c, 1);
}

BOOST_FIXTURE_TEST_CASE(InCsvRamp, ModelEllipsoidRampFixt)
{
    BOOST_CHECK_EQUAL(m_em.id, 0);
    BOOST_CHECK_EQUAL(m_em.a, 1);
    BOOST_CHECK_EQUAL(m_em.b, 2);
    BOOST_CHECK_EQUAL(m_em.c, 3);
}

BOOST_AUTO_TEST_SUITE_END() // TestSuiteModelEllipsoid