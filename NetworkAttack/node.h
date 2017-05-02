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
    float m_longitude;
    float m_latitude;

    std::vector<Edge *> m_incoming, m_outgoing;
    bool m_visited;
    Node * m_parent = NULL;
    short m_distance = 0;


public:
    short id() { return m_id; }
    void add_incoming(Edge *);
    void add_outgoing(Edge *);
    std::string city() { return m_city; }
    std::string state() { return m_state; }
    std::string country() { return m_country; }
    float latitude() { return m_latitude; }
    float longitude() { return m_longitude; }
    std::vector<Edge *> & incoming();
    std::vector<Edge *> & outgoing();
    bool visited() const { return m_visited; }
    void visited(const bool visited) { m_visited = visited; }
    Node * parent(){ return m_parent; }
    void setparent(Node * p){ m_parent = p; }
    Node(short id,
         std::string city,
         std::string state,
         std::string country,
         float longitude,
         float latitude)
        : m_id(id),
          m_city(city),
          m_state(state),
          m_country(country),
          m_longitude(longitude),
          m_latitude(latitude) { }
    Node(const Node &);
};



#endif // NODE_H
