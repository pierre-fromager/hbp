
#include "humanbody.h"

Human::Body::Body()
{
    build();
    connect();
}

Human::Body::~Body()
{
    m_limbs.clear();
}

DLinkedNode *Human::Body::limb(unsigned int id)
{
    std::vector<DLinkedNode *> f_limbs;
    std::copy_if(
        std::begin(m_limbs),
        std::end(m_limbs),
        std::back_inserter(f_limbs),
        [id](DLinkedNode *node) {
            return node->getId() == id;
        });
    return f_limbs.front();
}

void Human::Body::addLimb(unsigned int id)
{
    m_limbs.push_back(new DLinkedNode(id));
}

void Human::Body::build()
{
    addLimb(Human::Limbs::Id::HEAD);
    addLimb(Human::Limbs::Id::TRUNC);
    addLimb(Human::Limbs::Id::ARM_L_UP);
    addLimb(Human::Limbs::Id::ARM_L_LO);
    addLimb(Human::Limbs::Id::ARM_L_HAND);
    addLimb(Human::Limbs::Id::ARM_R_UP);
    addLimb(Human::Limbs::Id::ARM_R_LO);
    addLimb(Human::Limbs::Id::ARM_R_HAND);
    addLimb(Human::Limbs::Id::LEG_L_UP);
    addLimb(Human::Limbs::Id::LEG_L_LO);
    addLimb(Human::Limbs::Id::LEG_L_FOOT);
    addLimb(Human::Limbs::Id::LEG_R_UP);
    addLimb(Human::Limbs::Id::LEG_R_LO);
    addLimb(Human::Limbs::Id::LEG_R_FOOT);
}

void Human::Body::connect()
{
    limb(Human::Limbs::Id::HEAD)->setPrev(limb(Human::Limbs::Id::TRUNC));
    limb(Human::Limbs::Id::ARM_L_UP)->setPrev(limb(Human::Limbs::Id::TRUNC));
    limb(Human::Limbs::Id::ARM_R_UP)->setPrev(limb(Human::Limbs::Id::TRUNC));
    limb(Human::Limbs::Id::LEG_L_UP)->setPrev(limb(Human::Limbs::Id::TRUNC));
    limb(Human::Limbs::Id::LEG_R_UP)->setPrev(limb(Human::Limbs::Id::TRUNC));
    limb(Human::Limbs::Id::ARM_L_UP)->setNext(limb(Human::Limbs::Id::ARM_L_LO));
    limb(Human::Limbs::Id::ARM_L_LO)->setNext(limb(Human::Limbs::Id::ARM_L_HAND));
    limb(Human::Limbs::Id::ARM_L_HAND)->setPrev(limb(Human::Limbs::Id::ARM_L_LO));
    limb(Human::Limbs::Id::ARM_L_LO)->setPrev(limb(Human::Limbs::Id::ARM_L_UP));
    limb(Human::Limbs::Id::ARM_R_UP)->setNext(limb(Human::Limbs::Id::ARM_R_LO));
    limb(Human::Limbs::Id::ARM_R_LO)->setNext(limb(Human::Limbs::Id::ARM_R_HAND));
    limb(Human::Limbs::Id::ARM_R_HAND)->setPrev(limb(Human::Limbs::Id::ARM_R_LO));
    limb(Human::Limbs::Id::ARM_R_LO)->setPrev(limb(Human::Limbs::Id::ARM_R_UP));
    limb(Human::Limbs::Id::LEG_L_UP)->setNext(limb(Human::Limbs::Id::LEG_L_LO));
    limb(Human::Limbs::Id::LEG_L_LO)->setNext(limb(Human::Limbs::Id::LEG_L_FOOT));
    limb(Human::Limbs::Id::LEG_L_FOOT)->setPrev(limb(Human::Limbs::Id::LEG_L_LO));
    limb(Human::Limbs::Id::LEG_L_LO)->setPrev(limb(Human::Limbs::Id::LEG_L_UP));
    limb(Human::Limbs::Id::LEG_R_UP)->setNext(limb(Human::Limbs::Id::LEG_R_LO));
    limb(Human::Limbs::Id::LEG_R_LO)->setNext(limb(Human::Limbs::Id::LEG_R_FOOT));
    limb(Human::Limbs::Id::LEG_R_FOOT)->setPrev(limb(Human::Limbs::Id::LEG_R_LO));
    limb(Human::Limbs::Id::LEG_R_LO)->setPrev(limb(Human::Limbs::Id::LEG_R_UP));
}

void Human::Body::pulse()
{
    std::vector<DLinkedNode *> refs = backReferences(Human::Limbs::Id::TRUNC);
    size_t refscnt;
    const size_t nbelt = refs.size();
    for (refscnt = 0; refscnt < nbelt; refscnt++)
        propForward(refs[refscnt]->getId());
}

std::vector<DLinkedNode *> Human::Body::backReferences(unsigned int id)
{
    DLinkedNode *current = limb(id);
    std::vector<DLinkedNode *> back_references;
    std::copy_if(
        std::begin(m_limbs),
        std::end(m_limbs),
        std::back_inserter(back_references),
        [current](DLinkedNode *node) {
            return node->getPrev() == current;
        });
    return back_references;
}

void Human::Body::propBackward(unsigned int id)
{
    DLinkedNode *cur = limb(id);
    //std::cout << "backward" << std::endl;
    while (cur != nullptr)
    {
        propCallback(cur);
        cur = cur->getPrev();
    }
}

void Human::Body::propForward(unsigned int id)
{
    DLinkedNode *cur = limb(id);
    //std::cout << "forward" << std::endl;
    while (cur != nullptr)
    {
        propCallback(cur);
        cur = cur->getNext();
    }
}
