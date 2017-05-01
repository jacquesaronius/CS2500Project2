#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "parser.h"
#include "path.h"
#include <vector>

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
signals:

public slots:
};

#endif // CONTROLLER_H
