
#ifndef H_ELLIPSOID
#define H_ELLIPSOID

#include <math.h>
typedef long double ld;

class Ellipsoid
{

public:
    Ellipsoid(ld a, ld b, ld c);
    ld volume();
    ld surface();
    ld ratiosv();

private:
    ld m_p;
    ld m_pi;
    ld m_a;
    ld m_b;
    ld m_c;
};

#endif