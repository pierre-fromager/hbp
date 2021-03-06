
#ifndef H_ELLIPSOID
#define H_ELLIPSOID

typedef long double ld;
#include "model/ellipsoid.h"
#include <math.h>

/**
 * @brief Calculate ellipsoid volume and surface
 * @url https://planetcalc.com/149/
 */
class Ellipsoid
{

public:
    Ellipsoid();
    Ellipsoid(unsigned int id, ld a, ld b, ld c);
    unsigned int getId();
    ld getA();
    ld getB();
    ld getC();
    void setId(unsigned int id);
    void setA(ld a);
    void setB(ld b);
    void setC(ld c);
    ld volume();
    ld surface();
    ld ratiosv();

private:
    unsigned int m_id;
    ld m_p;
    ld m_pi;
    ld m_a;
    ld m_b;
    ld m_c;
};

#endif