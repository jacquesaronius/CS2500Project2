#include "path.h"

Path::Path()
{
    m_flow=0;
}

void Path::add_edge(Edge e)
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

void Path::adde(Edge* e)
{
    medge.push_back(e);
}

std::vector<Edge*> Path::mredges()
{
    std::vector<Edge*> e;

    for (auto i = medge.begin(); i != medge.end(); i++)
    {
        e.push_back(*i);
    }

    return e;
}
