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

std::vector<Edge> Path::edges()
{
    std::vector<Edge> v;

    for (auto i = m_edges.begin(); i != m_edges.end(); i++)
    {
        Edge e((**i));
        v.push_back(e);
    }

    return v;
}
