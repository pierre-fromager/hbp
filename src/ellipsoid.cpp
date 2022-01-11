
#include "ellipsoid.h"

Ellipsoid::Ellipsoid(unsigned int id, ld a, ld b, ld c) : m_id(id), m_a(a), m_b(b), m_c(c)
{
    m_p = 1.6075;
    m_pi = 4 * atan(1);
}

unsigned int Ellipsoid::getId()
{
    return m_id;
}

ld Ellipsoid::volume()
{
    return (4 * m_pi * m_a * m_b * m_c) / 3;
}

ld Ellipsoid::surface()
{
    const ld ap = pow(m_a, m_p);
    const ld bp = pow(m_b, m_p);
    const ld cp = pow(m_c, m_p);
    const ld t = ((ap * bp) + (ap * cp) + (bp * cp)) / 3;
    return 4 * m_pi * pow(t, (1 / m_p));
}

ld Ellipsoid::ratiosv()
{
    const ld v = volume();
    if (v == 0)
        return 0;
    return surface() / v;
}
