
#ifndef H_HUMAN
#define H_HUMAN

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "humanlimbs.h"
#include "dlinkednode.h"

namespace Human
{
class Body
{

public:
    Body();
    ~Body();
    DLinkedNode *limb(unsigned int id);
    void pulse();
    std::vector<DLinkedNode *> backReferences(unsigned int id);
    void propBackward(unsigned int id/*,const std::function<void(DLinkedNode)> &propCallback*/);
    void propForward(unsigned int id/*,const std::function<void(DLinkedNode)> &propCallback*/);
    std::function<void(DLinkedNode*)> propCallback;

private:
    void build();
    void connect();
    void addLimb(unsigned int id);
    std::vector<DLinkedNode *> m_limbs;
};

} // namespace Human

#endif