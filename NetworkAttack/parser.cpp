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

    const short NODE_MODE = 1;
    const bool EDGE_MODE = 2;
    short mode = 0;
    std::map<std::string, std::string> dictionary;
    std::vector<short> sources, targets, ids;
    QRegExp regex("\\s*(.*?)\\s\"?\?(.*?)\"?");

    QFile file(file_name);

    deallocate();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Failed to open file for parsing");
        return false;
    }

    while (!file.atEnd())
    {

        std::string key;
        std::string value;
        QString line = file.readLine();
        if (line.contains(QRegExp("node\\s\\[")))
            mode = NODE_MODE;

        if (line.contains(QRegExp("edge\\s\\[")))
            mode = EDGE_MODE;

        if (regex.indexIn(line) != -1)
        {
            key = regex.cap(1).toStdString();
            value = regex.cap(2).toStdString();
            dictionary.emplace(std::pair<std::string, std::string>(key, value));
        }
        else
        {
            if (mode == NODE_MODE)
            {
                Node * t = new Node(std::stoi(dictionary["id"]),
                                    dictionary["label"],
                                    dictionary["geocode_append"],
                                    dictionary["Country"],
                                    std::stof(dictionary["Latitude"]),
                                    std::stof(dictionary["Longitude"]));
                m_nodes.push_back(t);
                dictionary.clear();
            }
            else if (mode == EDGE_MODE)
            {
                ids.push_back(std::stoi(dictionary["id"]));
                sources.push_back(std::stoi(dictionary["source"]));
                targets.push_back(std::stoi(dictionary["target"]));
                dictionary.clear();
            }
        }

    }

    /* Sort nodes by ID */


    /* Create edges */

    for (unsigned int i = 0; i < ids.size(); i++)
    {
        Edge * t = new Edge(ids[i],
                            m_nodes[sources[i]],
                            m_nodes[targets[i]]);
        m_edges.push_back(t);

    }

    return true;

}
