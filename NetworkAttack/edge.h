#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    short m_id;
    Node * m_source;
    Node * m_target;
    bool m_alive;
public:
    short id() { return m_id; }
    Node source() { return Node(* m_source); }
    Node target() { return Node(* m_target); }
    bool alive() { return m_alive; }
    void alive(bool alive) { m_alive = alive; }
    Edge(short id, Node * source, Node * target)
        : m_id(id), m_source(source), m_target(target), m_alive(0) { }
    Edge(const Edge &);

};

#endif // EDGE_H
