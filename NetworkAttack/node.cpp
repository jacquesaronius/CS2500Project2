#include "node.h"

Node::Node(const Node & rhs)
{
    m_id = rhs.m_id;
    m_city = rhs.m_city;
    m_state = rhs.m_state;
    m_country = rhs.m_country;
    m_latitude = rhs.m_latitude;
    m_longitude = rhs.m_longitude;
}
