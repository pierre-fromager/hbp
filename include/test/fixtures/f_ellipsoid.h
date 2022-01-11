
#ifndef TEST_ELLIPSOID_FIXTURE_H
#define TEST_ELLIPSOID_FIXTURE_H

#include "ellipsoid.h"
#include "f_common.h"

struct TestEllipsoidFixt : TestBaseFixt
{
    TestEllipsoidFixt(
        unsigned int id,
        long double a,
        long double b,
        long double c) : m_id(id),
                         m_a(a),
                         m_b(b),
                         m_c(c)
    {
        BOOST_TEST_MESSAGE(m_setup);
        ell = new Ellipsoid(m_id, m_a, m_b, m_c);
    }
    ~TestEllipsoidFixt()
    {
        BOOST_TEST_MESSAGE(m_teardown);
        delete ell;
    }
    Ellipsoid *ell;
    unsigned int m_id;
    long double m_a;
    long double m_b;
    long double m_c;
};

struct EllipsoidZeroesFixt : public TestEllipsoidFixt
{
    EllipsoidZeroesFixt() : TestEllipsoidFixt(0, 0, 0, 0) {}
};

struct EllipsoidIdOnesFixt : public TestEllipsoidFixt
{
    EllipsoidIdOnesFixt() : TestEllipsoidFixt(1, 1, 1, 1) {}
};

struct EllipsoidIdTwosFixt : public TestEllipsoidFixt
{
    EllipsoidIdTwosFixt() : TestEllipsoidFixt(2, 2, 2, 2) {}
};

#endif