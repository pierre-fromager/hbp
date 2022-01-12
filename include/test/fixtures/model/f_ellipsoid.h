
#ifndef TEST_MODEL_ELLIPSOID_FIXTURE_H
#define TEST_MODEL_ELLIPSOID_FIXTURE_H

#include "model/ellipsoid.h"
#include "f_common.h"

struct TestModelEllipsoidCsvFixt : TestBaseFixt
{
    TestModelEllipsoidCsvFixt(const std::string &csv_line) : m_csv_line(csv_line)
    {
        BOOST_TEST_MESSAGE(m_setup);
        std::replace(m_csv_line.begin(), m_csv_line.end(), m_sep, ' ');
        std::stringstream input;
        input << m_csv_line;
        input >> m_em;
    }
    ~TestModelEllipsoidCsvFixt()
    {
        BOOST_TEST_MESSAGE(m_teardown);
    }
    Model::Ellipsoid m_em;
    std::string m_csv_line;
    unsigned int m_id;
    long double m_a;
    long double m_b;
    long double m_c;
    const char m_sep = ';';
};

struct ModelEllipsoidZeroesFixt : public TestModelEllipsoidCsvFixt
{
    ModelEllipsoidZeroesFixt() : TestModelEllipsoidCsvFixt("0;0;0;0") {}
};

struct ModelEllipsoidOnesFixt : public TestModelEllipsoidCsvFixt
{
    ModelEllipsoidOnesFixt() : TestModelEllipsoidCsvFixt("1;1;1;1") {}
};

struct ModelEllipsoidRampFixt : public TestModelEllipsoidCsvFixt
{
    ModelEllipsoidRampFixt() : TestModelEllipsoidCsvFixt("0;1;2;3") {}
};

#endif