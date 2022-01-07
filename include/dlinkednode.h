
#ifndef H_DLINKEDNODE
#define H_DLINKEDNODE

#include <string>
#include "datanode.h"

class DLinkedNode : public DataNode
{

public:
    DLinkedNode(unsigned int id);
    friend unsigned int getId();
    DLinkedNode *getPrev();
    DLinkedNode *getNext();
    void setPrev(DLinkedNode *node);
    void setNext(DLinkedNode *node);

private:
    DLinkedNode *m_prev;
    DLinkedNode *m_next;
};

#endif