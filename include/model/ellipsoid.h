
#ifndef MODEL_ELLIPSOID_H
#define MODEL_ELLIPSOID_H

#include <string>
#include <iostream>

namespace Model
{

struct Ellipsoid
{
    unsigned int id;
    ld a;
    ld b;
    ld c;
    friend std::ostream &operator<<(std::ostream &os, const Ellipsoid &e)
    {
        const std::string &sep = ";";
        os << e.id << e.a << sep << e.b << sep << e.c;
        return os;
    };
    friend std::istream &operator>>(std::istream &is, Ellipsoid &e)
    {
        is >> e.id >> e.a >> e.b >> e.c;
        return is;
    };
};

} // namespace Model

#endif