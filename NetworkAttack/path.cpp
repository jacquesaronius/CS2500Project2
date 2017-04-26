#include "path.h"

void Path::add_edge(const Edge e)
{
    std::shared_ptr<Edge> p(std::make_shared<Edge>(e));
    m_edges.push_back(p);
}

std::shared_ptr<Edge> Path::operator [](const size_t i) const
{
    return m_edges[i];
}
