
#include "node.h"

Node::Node(unsigned int id) : m_id(id),
                              m_data(0)
{
}

unsigned int Node::getId()
{
    return m_id;
}

int Node::getData()
{
    return m_data;
}

void Node::setData(int data)
{
    m_data = data;
}
