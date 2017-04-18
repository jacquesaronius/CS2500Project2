#include "edge.h"

Edge::Edge(const Edge & rhs)
{
    m_id = rhs.m_id;
    m_source = rhs.m_source;
    m_target = rhs.m_target;
}
