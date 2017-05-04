#ifndef PATH_H
#define PATH_H
#include "edge.h"
#include <memory>
#include <vector>

class Path
{
    std::vector<std::shared_ptr<Edge>> m_edges;
    std::vector<Edge*> medge;
    short m_flow;
public:
    Path();
    void add_edge(Edge e);
    short flow() const { return m_flow; }
    void flow(const short flow) { m_flow = flow; }
    std::shared_ptr<Edge> operator[](const size_t) const;
    std::vector<Edge> edges();
    void adde(Edge* e);
    std::vector<Edge*> mredges();
};
#endif // PATH_H
