#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "parser.h"

class Controller : public QObject
{
    Q_OBJECT

    Parser * parser;
public:
    explicit Controller(QObject *parent = 0);
    int maxFlow(int graph[m_nodes.size()][m_nodes.size()], Node* s, Node *t);
    int ** Calculategraph();
    path AugmentingPath(int Graph[m_nodes.size()][m_nodes.size()], Node* s, Node* t);
    bool bfs(int rGraph[m_nodes.size()][m_nodes.size()], Node* s, Node* t);

signals:

public slots:
};

#endif // CONTROLLER_H
