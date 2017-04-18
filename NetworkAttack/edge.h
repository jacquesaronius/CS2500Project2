#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    short m_id;
    Node * m_source;
    Node * m_target;
public:
    short id() { return m_id; }
    Node source() { return Node(* m_source); }
    Node target() { return Node(* m_target); }
    Edge(short id, Node * source, Node * target)
        : m_id(id), m_source(source), m_target(target) { }
    Edge(const Edge &);

};

#endif // EDGE_H
