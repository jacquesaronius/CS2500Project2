#include "edge.h"

Edge::Edge(const Edge & rhs)
{
    m_id = rhs.m_id;
    m_alive = rhs.m_alive;
}


void Edge::calc_capacity()
{
   m_capacity = rand() % MAX_CAPACITY + MIN_CAPACITY;
}
Edge::Edge()
{
    m_id=0;
    m_capacity=0;
    m_flow=0;
    m_visited=false;
    m_source=NULL;
    m_target=NULL;
    m_alive=false;
}
