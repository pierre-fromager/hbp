
#include "node.h"

template <typename T>
Node<T>::Node(unsigned int id) : m_id(id),
                                 m_data(nullptr)
{
}

template <typename T>
unsigned int Node<T>::getId()
{
    return m_id;
}

template <typename T>
T Node<T>::getData()
{
    return m_data;
}

template <typename T>
void Node<T>::setData(T data)
{
    m_data = data;
}
