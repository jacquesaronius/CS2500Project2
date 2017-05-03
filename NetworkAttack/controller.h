#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QString>
#include <vector>
#include <QTextStream>
#include "parser.h"
#include "path.h"
#include <ctime>
using namespace std;

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(short kvalue READ kvalue WRITE setKvalue)
    Q_PROPERTY(short delay READ delay WRITE setDelay)
    Q_PROPERTY(short mode READ mode WRITE setMode)
    Q_PROPERTY(short attackMode READ attackMode WRITE setAttackMode)
    Q_PROPERTY(short rounds READ rounds WRITE setRounds)
    Q_PROPERTY(QString status READ status)



    std::vector<Path> paths;
    std::vector<Node> nodes;
    std::vector<QString> reports;
    Parser * parser;
    short m_kvalue = 50;
    short m_rounds = 0;
    short m_delay = 50;
    short m_mode;
    short m_attack_mode;
    Node * m_source;
    Node * m_target;
    QString m_status;
public:

    static const short MODE_STATIC_ROUTING=0;
    static const short MODE_REACTIVE_ROUTING=1;
    static const short MODE_BASE_ATTACK=0;
    static const short MODE_STATIC_ATTACK=1;
    static const short MODE_REACTIVE_ATTACK=2;
    static const short REPORT_TIME_BASE_ATTACK = 0;
    static const short REPORT_50_BASE_ATTACK = 1;
    static const short REPORT_K_BASE_ATTACK = 2;
    static const short REPORT_TIME_STATIC_ATTACK = 3;
    static const short REPORT_50_STATIC_ATTACK = 4;
    static const short REPORT_K_STATIC_ATTACK = 5;
    static const short REPORT_TIME_REACT_ATTACK = 6;
    static const short REPORT_50_REACT_ATTACK = 7;
    static const short REPORT_K_REACT_ATTACK = 8;




    explicit Controller(QObject *parent = 0);
    short kvalue() { return m_kvalue; }
    void setKvalue(short kvalue) { m_kvalue = kvalue; }
    short delay() { return m_delay; }
    void setDelay(short delay) { m_delay = delay; }
    short rounds() { return m_rounds; }
    void setRounds(short rounds) { m_rounds = rounds; }
    short mode() { return m_mode; }
    void setMode(short mode) { m_mode = mode; }
    short attackMode() { return m_attack_mode; }
    void setAttackMode(short attack) { m_attack_mode = attack; }
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
    void ReActiveRouting();
    void StaticRouting();
    int StaticRoutingFlow(Edge* e, int mflow);
    void Source(Node * s){m_source =s;}
    Node* Source(){return m_source;}
    void Target(Node * t){m_target =t;}
    Node* Target(){return m_target;}
    void write_report(short modes);
    void update_report_data(short mode, short round, short maxFlow);

    Q_INVOKABLE void attack();
    Q_INVOKABLE void reset();
    Q_INVOKABLE void create();

    int test_import();
    int test_calculate_graph();
    int test_node_copy();
    QString status() { return m_status; }

signals:
    void update();

public slots:
};

#endif // CONTROLLER_H
