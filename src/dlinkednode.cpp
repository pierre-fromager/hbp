#include "dlinkednode.h"

DLinkedNode::DLinkedNode(unsigned int id) : Node(id),                              
                              m_prev(nullptr),
                              m_next(nullptr)
{
}

DLinkedNode *DLinkedNode::getPrev()
{
    return m_prev;
}

DLinkedNode *DLinkedNode::getNext()
{
    return m_next;
}

void DLinkedNode::setPrev(DLinkedNode *node)
{
    m_prev = node;
}

void DLinkedNode::setNext(DLinkedNode *node)
{
    m_next = node;
}
