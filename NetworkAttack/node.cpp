#include "node.h"
#include "edge.h"
#include <QDebug>

Node::Node(const Node & rhs)
{
    m_id = rhs.m_id;
    m_city = rhs.m_city;
    m_state = rhs.m_state;
    m_country = rhs.m_country;
    m_latitude = rhs.m_latitude;
    m_longitude = rhs.m_longitude;
}

std::vector<Edge *> & Node::incoming()
{
    return m_incoming;
}


std::vector<Edge *> & Node::outgoing()
{
    return m_outgoing;
}

void Node::add_incoming(Edge * e)
{
    m_incoming.push_back(e);
}

void Node::add_outgoing(Edge * e)
{
    m_outgoing.push_back(e);
}
