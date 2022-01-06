
#include "ellipsoid.h"

Ellipsoid::Ellipsoid(ld a, ld b, ld c) : m_a(a), m_b(b), m_c(c)
{
    m_p = 1.6075;
    m_pi = 4 * atan(1);
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
    return surface() / volume();
}