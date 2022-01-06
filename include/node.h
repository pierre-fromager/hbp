
#ifndef H_NODE
#define H_NODE

#include <string>

template <typename T>
class Node
{

public:
    Node(unsigned int id);
    unsigned int getId();
    T getData();
    void setData(T data);

protected:
    unsigned int m_id;
    T m_data;
};

//#include "../src/node.cpp"

#endif