
#include "datanode.h"

DataNode::DataNode(unsigned int id) : Node(id)
{
}

int DataNode::getData()
{
    return m_data;
}

void DataNode::setData(int data)
{
    m_data = data;
}
