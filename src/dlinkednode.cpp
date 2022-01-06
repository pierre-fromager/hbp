#include "dlinkednode.h"

DLinkedNode<T>::DLinkedNode(unsigned int id) : Node(id),                              
                              m_prev(nullptr),
                              m_next(nullptr)
{
}

DLinkedNode *DLinkedNode<T>::getPrev()
{
    return m_prev;
}

DLinkedNode *DLinkedNode<T>::getNext()
{
    return m_next;
}

void DLinkedNode<T>::setPrev(DLinkedNode *node)
{
    m_prev = node;
}

void DLinkedNode<T>::setNext(DLinkedNode *node)
{
    m_next = node;
}
