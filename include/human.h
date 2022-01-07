
#ifndef H_HUMAN
#define H_HUMAN

#include <iostream>
#include <vector>
#include <algorithm>
//#include "datanode.h"
#include "dlinkednode.h"

namespace Human
{

namespace Limbs
{
enum Id
{
    TRUNC = 0,
    HEAD = 1,
    ARM_L_UP = 10,
    ARM_L_LO = 11,
    ARM_L_HAND = 12,
    ARM_R_UP = 20,
    ARM_R_LO = 21,
    ARM_R_HAND = 22,
    LEG_L_UP = 30,
    LEG_L_LO = 31,
    LEG_L_FOOT = 32,
    LEG_R_UP = 40,
    LEG_R_LO = 41,
    LEG_R_FOOT = 42,
};
}

class Body
{

public:
    Body();
    ~Body();
    DLinkedNode<int> *limb(unsigned int id);
    void pulse();
    std::vector<DLinkedNode<int> *> backReferences(unsigned int id);
    void propBackward(unsigned int id);
    void propForward(unsigned int id);

private:
    void build();
    void connect();
    void addLimb(unsigned int id);
    std::vector<DLinkedNode<int> *> m_limbs;
};

} // namespace Human

#endif