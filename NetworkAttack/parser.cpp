#include "parser.h"

Parser::Parser(QObject *parent) : QObject(parent)
{
}

void Parser::deallocate()
{
    for (auto i = m_nodes.begin(); i != m_nodes.end(); i++)
        delete (*i);

    for (auto i = m_edges.begin(); i != m_edges.end(); i++)
        delete (*i);

    m_nodes.clear();
    m_edges.clear();
}

std::vector<Edge> Parser::edges()
{
    std::vector<Edge> e;

    for (auto i = m_edges.begin(); i != m_edges.end(); i++)
    {
        Edge t(*(*i));
        e.push_back(t);
    }

    return e;
}

std::vector<Node> Parser::nodes()
{
    std::vector<Node> n;

    for (auto i = m_nodes.begin(); i != m_nodes.end(); i++)
    {
        Node t(*(*i));
        n.push_back(t);
    }

    return n;
}

bool Parser::parse(const QString file_name)
{
    QString regex = "\s*(.*?)\s\"??(.*?)\"?";
    const short NODE_MODE = 1;
    const bool EDGE_MODE = 2;
    short mode = 0;

    QFile file(file_name);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Failed to open file for parsing");
        return false;
    }

    while (!file.atEnd())
    {


        QString line = file.readLine();
        if (line.contains(QRegExp("node\\s\\[")))
            mode = NODE_MODE;

        if (line.contains(QRegExp("edge\\s\\[")))
            mode = EDGE_MODE;

    }

}
