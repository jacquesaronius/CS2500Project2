#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QRegularExpression>
#include <vector>
#include <map>
#include "node.h"
#include "edge.h"

class Parser : public QObject
{
    Q_OBJECT
    std::vector<Node *> m_nodes;
    std::vector<Edge *> m_edges;
    void deallocate();
    std::tuple<float, float> lng_lat();


public:
    bool parse(const QString);
    bool import();
    Edge edge(short id);
    Node node(short id);
    std::vector<Node> nodes();
    std::vector<Edge> edges();
    Node * create_blacksite();
    explicit Parser(QObject *parent = 0);
    ~Parser() { deallocate(); }

signals:

public slots:
};

#endif // PARSER_H
