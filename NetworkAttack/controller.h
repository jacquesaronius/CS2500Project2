#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <QObject>
#include <vector>
#include "parser.h"
#include "path.h"
#include <ctime>
using namespace std;

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(short kvalue READ kvalue WRITE setKvalue)
    Q_PROPERTY(short delay READ delay WRITE setDelay)


    std::vector<Path> paths;
    std::vector<Node> nodes;
    Parser * parser;
    short m_kvalue = 50;
    short m_rounds = 0;
    short m_delay = 50;

public:
    static const short report_time_base_attack = 0;
    static const short report_50_base_attack = 1;
    static const short report_k_base_attack = 2;
    static const short report_time_static_attack = 3;
    static const short report_50_static_attack = 4;
    static const short report_k_static_attack = 5;
    static const short report_time_react_attack = 6;
    static const short report_50_react_attack = 7;
    static const short report_k_react_attack = 8;

    explicit Controller(QObject *parent = 0);
    short kvalue() { return m_kvalue; }
    void setKvalue(short kvalue) { m_kvalue = kvalue; }
    short delay() { return m_delay; }
    void setDelay(short delay) { m_delay = delay; }
    short rounds() { return m_rounds; }
    void setRounds(short rounds) { m_rounds = rounds; }
    int test_parser();
    int maxFlow(int **graph, Node* s, Node *t);
    int ** Calculategraph();
    Path AugmentingPath(int **graph, Node* s, Node* t);
    bool BFS(int **rgraph, Node* s, Node* t);
    void addpath(Path path);
    int ** RemoveEdge(int **graph, Edge* e);
    Edge* react_attack();
    Edge* static_attack();
    Edge* base_attack();
    void ReActiveRouting(Node * s, Node * t);
    void StaticRouting(Node * s, Node * t);
    int StaticRoutingFlow(Edge* e, int mflow);
    void write_report(short id);
    void attack();
    int test_import();
    int test_calculate_graph();
    int test_node_copy();

signals:
    void update();

public slots:
};

#endif // CONTROLLER_H
