
#ifndef H_NODE
#define H_NODE

#include <string>

class Node
{

public:
    Node(unsigned int id);
    unsigned int getId();

protected:
    unsigned int m_id;
};

#endif