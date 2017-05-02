#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <QObject>
#include <vector>
#include "parser.h"
#include "path.h"
using namespace std;

class Controller : public QObject
{
    Q_OBJECT

    std::vector<Path> paths;
    Parser * parser;
public:

    explicit Controller(QObject *parent = 0);
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
    Node* Source();
signals:
    void update();

public slots:
};

#endif // CONTROLLER_H
