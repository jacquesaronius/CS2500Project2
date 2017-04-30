#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
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

signals:

public slots:
};

#endif // CONTROLLER_H
