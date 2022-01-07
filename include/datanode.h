
#ifndef H_DATANODE
#define H_DATANODE

#include "node.h"

template <typename Item>
class DataNode : public Node
{

public:
    DataNode(unsigned int id);
    friend unsigned int getId();
    Item getData();
    void setData(Item data);

private:
    Item m_data;
};

#endif