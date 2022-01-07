
#include "datanode.h"

template <typename Item>
DataNode<Item>::DataNode(unsigned int id) : Node(id)
{
}

template <typename Item>
Item DataNode<Item>::getData()
{
    return m_data;
}

template <typename Item>
void DataNode<Item>::setData(Item data)
{
    m_data = data;
}
