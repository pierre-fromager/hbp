
#ifndef H_DLINKEDNODE
#define H_DLINKEDNODE

#include <string>
#include "node.h"

template <typename T>
class DLinkedNode : public Node<T>
{

public:
    DLinkedNode<T>(unsigned int id);
    friend unsigned int getId();
    DLinkedNode <T>*getPrev();
    DLinkedNode <T>*getNext();
    void setPrev<T>(DLinkedNode *node);
    void setNext<T>(DLinkedNode *node);

protected:
    unsigned int m_id;

private:
    DLinkedNode *m_prev;
    DLinkedNode *m_next;
};

#endif