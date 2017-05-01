#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>
#include "parser.h"
#include "path.h"

class Controller : public QObject
{
    Q_OBJECT

    Parser * parser;
public:
    explicit Controller(QObject *parent = 0);
    int test_parser();
    int maxFlow(int **, Node* s, Node *t);
    int ** Calculategraph();
    Path AugmentingPath(int **, Node* s, Node* t);
    bool bfs(int **, Node* s, Node* t);
    void react_attack(vector<path> &paths);
    void static_attack(vector<path> &paths);
    void Controller::base_attack(vector<Edges> &edges);

signals:

public slots:
};

#endif // CONTROLLER_H
