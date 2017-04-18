#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <vector>
#include "node.h"
#include "edge.h"

class Parser : public QObject
{
    Q_OBJECT
    std::vector<Node *> m_nodes;
    std::vector<Edge *> m_edges;
    void deallocate();

public:
    bool parse(const QString);
    Edge edge(short id);
    Node node(short id);
    std::vector<Node> nodes();
    std::vector<Edge> edges();
    explicit Parser(QObject *parent = 0);
    ~Parser() { deallocate(); }

signals:

public slots:
};

#endif // PARSER_H
