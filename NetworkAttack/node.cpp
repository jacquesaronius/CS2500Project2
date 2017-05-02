#include "node.h"
#include "edge.h"

Node::Node(const Node & rhs)
{
    m_id = rhs.m_id;
    m_city = rhs.m_city;
    m_state = rhs.m_state;
    m_country = rhs.m_country;
    m_latitude = rhs.m_latitude;
    m_longitude = rhs.m_longitude;

    for (auto i = rhs.m_incoming.begin(); i != rhs.m_incoming.end(); i++)
    {
        m_incoming.push_back(*i);
    }

    for (auto i = rhs.m_outgoing.begin(); i != rhs.m_outgoing.end(); i++)
    {
        m_outgoing.push_back(*i);
    }
}

std::vector<Edge> Node::incoming()
{
    std::vector<Edge> v;

    for (auto i = m_incoming.begin(); i != m_incoming.end(); i++)
    {
        Edge e((**i));
        v.push_back(e);
    }

    return v;
}


std::vector<Edge> Node::outgoing()
{
    std::vector<Edge> v;


    for (auto i = m_outgoing.begin(); i != m_outgoing.end(); i++)
    {
        Edge e((**i));
        v.push_back(e);
    }

    return v;
}

void Node::add_incoming(Edge * e)
{
    m_incoming.push_back(e);
}

void Node::add_outgoing(Edge * e)
{
    m_outgoing.push_back(e);
}
