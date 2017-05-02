#ifndef PATH_H
#define PATH_H
#include "edge.h"
#include <memory>


class Path
{
    std::vector<std::shared_ptr<Edge>> m_edges;
    short m_flow;
public:
    Path() : m_flow(0) { }
    void add_edge(const Edge);
    short flow() const { return m_flow; }
    void flow(const short flow) { m_flow = flow; }
    std::shared_ptr<Edge> operator[](const size_t) const;
    std::vector<Edge> edges();;
};
#endif // PATH_H
