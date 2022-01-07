
#ifndef H_DATANODE
#define H_DATANODE

#include "node.h"

class DataNode : public Node
{

public:
    DataNode(unsigned int id);
    friend unsigned int getId();
    int getData();
    void setData(int data);

protected:
    int m_data;
};

#endif