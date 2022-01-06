
#ifndef H_NODE
#define H_NODE

#include <string>

class Node
{

public:
    Node(unsigned int id);
    unsigned int getId();
    int getData();
    void setData(int data);

protected:
    unsigned int m_id;
    int m_data;
};

//#include "../src/node.cpp"

#endif