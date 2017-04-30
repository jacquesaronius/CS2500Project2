#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

class Edge;

class Node
{
    short m_id;
    std::string m_city;
    std::string m_state;
    std::string m_country;
    float m_latitude;
    float m_longitude;
    std::vector<Edge *> m_incoming, m_outgoing;
    bool m_visited;
    Node * m_parent = NULL;
    short m_distance = 0;


public:
    short id() { return m_id; }
    std::string city() { return m_city; }
    std::string state() { return m_state; }
    std::string country() { return m_country; }
    float latitude() { return m_latitude; }
    float longitude() { return m_longitude; }
    std::vector<Edge> incoming();
    std::vector<Edge> outgoing();
    bool visited() const { return m_visited; }
    void visited(const bool visited) { m_visited = visited; }

    Node(short id,
         std::string city,
         std::string state,
         std::string country,
         float latitude,
         float longitude)
        : m_id(id),
          m_city(city),
          m_state(state),
          m_country(country),
          m_latitude(latitude),
          m_longitude(longitude) { }
    Node(const Node &);
};



#endif // NODE_H
