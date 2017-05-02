#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    const short MIN_CAPACITY = 1;
    const short MAX_CAPACITY = 20;
    short m_id;
    short m_capacity;
    short m_flow;
    bool m_visited;
    Node* m_source;
    Node* m_target;
    bool m_alive;
    void calc_capacity();
public:
    short id() { return m_id; }
    short capacity() { return m_capacity; }
    void capacity(int c) {m_capacity = c;}
    short flow() { return m_flow; }
    void flow(short flow) { m_flow = flow; }
    bool visited() { return m_visited; }
    void visited(bool visited) { m_visited = visited; }
    Node source() { return Node(* m_source); }
    Node target() { return Node(* m_target); }
    bool alive() { return m_alive; }
    void alive(bool alive) { m_alive = alive; }
    Edge(Node * source, Node * target, short id)
        : m_id(id), m_source(source), m_target(target), m_alive(0)
    {
        calc_capacity();
    }
    Edge(const Edge &);
};

#endif // EDGE_H
