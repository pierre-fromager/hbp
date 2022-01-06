
#ifndef H_DLINKEDNODE
#define H_DLINKEDNODE

#include <string>
#include "node.h"

class DLinkedNode : public Node
{

public:
    DLinkedNode(unsigned int id);
    friend unsigned int getId();
    DLinkedNode *getPrev();
    DLinkedNode *getNext();
    void setPrev(DLinkedNode *node);
    void setNext(DLinkedNode *node);

protected:
    unsigned int m_id;

private:
    DLinkedNode *m_prev;
    DLinkedNode *m_next;
};

#endif