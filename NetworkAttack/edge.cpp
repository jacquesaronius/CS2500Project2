#include "edge.h"

Edge::Edge(const Edge & rhs)
{
    m_id = rhs.m_id;
    m_source = rhs.m_source;
    m_target = rhs.m_target;
    m_alive = rhs.m_alive;
}


void Edge::calc_capacity()
{
   m_capacity = rand() % MAX_CAPACITY + MIN_CAPACITY;
}
