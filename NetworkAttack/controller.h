#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>
#include "parser.h"
#include "path.h"
#include <iostream>

using namespace std;

class Controller : public QObject
{
    Q_OBJECT

    std::vector<Path> paths;
    Parser * parser;
public:

    explicit Controller(QObject *parent = 0);
    int test_parser();
    //int maxFlow(int **graph, Node* s, Node *t);
    int ** Calculategraph();
    //Path AugmentingPath(int **graph, Node* s, Node* t);
    //bool BFS(int **rgraph, Node* s, Node* t);
    //void addpath(Path path);
    //void react_attack(std::vector<Path> &paths);
    //void static_attack(std::vector<Path> &paths);
    //void base_attack(std::vector<Edge> &edges);
    //int StaticRoutingFlow(Edge e, int mflow);
    void test_calculate();
signals:

public slots:
};

#endif // CONTROLLER_H
