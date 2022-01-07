#include "dlinkednode.h"

template <typename Item>
DLinkedNode<Item>::DLinkedNode(unsigned int id) : DataNode<Item>(id)/*,                              
                              m_prev(nullptr),
                              m_next(nullptr)*/
{
}

template <typename Item>
DLinkedNode<Item> *DLinkedNode<Item>::getPrev()
{
    return m_prev;
}

template <typename Item>
DLinkedNode<Item> *DLinkedNode<Item>::getNext()
{
    return m_next;
}

template <typename Item>
void DLinkedNode<Item>::setPrev(DLinkedNode *node)
{
    m_prev = node;
}

template <typename Item>
void DLinkedNode<Item>::setNext(DLinkedNode *node)
{
    m_next = node;
}
