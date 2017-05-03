#include "controller.h"
#include <vector>

Controller::Controller(QObject *parent) : QObject(parent)
{
    parser = new Parser(this);
}

int Controller::test_parser()
{
    parser->parse("Kdl.gml");
    return 0;
}

int ** Controller::Calculategraph()
{
    int **graph=0;
    int k=0;
    graph = new int*[nodes.size()];
    for(auto i=nodes.begin(); i!=nodes.end(); i++)
    {
        graph[k]=new int[nodes.size()];
        auto outgoing = i->outgoing();
        for(auto it=outgoing.begin(); it!=outgoing.end(); it++)
        {
            if((*it)->visited()==false)
            {
                graph[i->id()][(*it)->target()->id()]=(*it)->capacity();
            }
        }
        k++;
    }
    return graph;
}

int Controller::maxFlow(int **graph, Node* s, Node *t)
{
    Node* u;
    Node* v;
    std::vector<Path> graphpaths;
    int ** rGraph=0;

    for (unsigned int i = 0; i < nodes.size(); i++)
    {
        graph[i]=new int[nodes.size()];
        for (unsigned int k = 0; k < nodes.size(); k++)
        {
             rGraph[i][k] = graph[i][k];
        }
    }

    int max_flow = 0;

    while(BFS(rGraph, s, t)==true)
    {

        Path P=AugmentingPath(rGraph, s, t);
        addpath(P);

        for (v=t; v != s; v=v->parent())
        {
            {
            u = v->parent();
            rGraph[u->id()][v->id()] -= P.flow();
            }
        }
        max_flow += P.flow();
    }
    return max_flow;
}

Path Controller::AugmentingPath(int **graph, Node* s, Node* t)
{
    Path Apath;
    bool cancontinue;
    Node * u;
    Node * v;
    int path_flow = 20;
    for (v=t; v!=s; v=v->parent())
    {
        u = v->parent();
        if(path_flow>graph[u->id()][v->id()])
            path_flow = graph[u->id()][v->id()];
    }
    v=t;
    int i=0;
    while(v!=s && cancontinue==true)
    {
        if(v!=s)
        {
          if(v->incoming()[i]->source()->id()==v->parent()->id())
          {
              Apath.add_edge(*(v->incoming()[i]));
              v=v->parent();
              i=0;
          }
          else
          {
              i++;
          }
        }
        if(v==s)
        {
            cancontinue=false;
        }
    }
    Apath.flow(path_flow);
    return Apath;
}

bool Controller::BFS(int **rgraph, Node* s, Node* t)
{
    for(unsigned int i=0; i<nodes.size(); i++)
        nodes[i].visited(false);

     std::vector <Node*> Q;
     Q.push_back(s);
     s->visited(true);
     s->setparent(NULL);

     while (!Q.empty())
     {
         Node* u = Q.front();
         Q.pop_back();

         for (unsigned int v=0; v < nodes.size(); v++)
         {
             if (nodes[v].visited()==false && rgraph[u->id()][nodes[v].id()] > 0)
             {
                 Q.push_back(&(nodes[v]));
                 nodes[v].setparent(u);
                 nodes[v].visited(true);
             }
         }
     }

     return (t->visited() == true);
}

void Controller::addpath(Path path)
{
    paths.push_back(path);
}

Edge* Controller::react_attack()
{
    Path p;
    std::vector<Edge> e;
    int max=0;
    int r=0;
    for (auto i=paths.begin(); i != paths.end(); i++)
    {
        if(i->flow()>max)
        {
            max=i->flow();
            p=(*i);
        }
    }
    r=p.edges().size();
    e=p.edges();
    m_rounds ++;
    return (&(e[r-2]));
}

Edge* Controller::static_attack()
{
    Path p;
    int r=0;
    std::vector<Edge> e;
    int i =rand() % paths.size();
    p = paths[i];
    r = p.edges().size();
    e=p.edges();
    m_rounds ++;
    return(&(e[r-2]));
}

Edge* Controller::base_attack()
{
    Path p;
    std::vector<Edge> e;
    int k=0;
    int i =rand() % paths.size();
    p = paths[i];
    e=p.edges();
    k = rand() % e.size();
    m_rounds ++;
    return(&(e[k]));
}


int Controller::StaticRoutingFlow(Edge* e, int mflow)
{
    for(auto i=paths.begin(); i!=paths.end(); i++)
    {
        for(auto it=i->edges().begin(); it!=i->edges().begin(); it++)
        {
            if(e->id() == it->id())
            {
                mflow -= i->flow();
            }
        }
    }
    return mflow;
}

int Controller::test_import()
{

    parser->import(50);
    return 0;
}

int Controller::test_calculate_graph()
{
    int ** graph;
    parser->import(50);
    graph = Calculategraph();

    size_t size = parser->nodes().size();

    for (size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
        {
            std::cout << graph[j][i];
            if (i < size - 1)
                std::cout << ",";
        }

        std::cout << std::endl;
    return 0;

}
void Controller::StaticRouting()
{
    int **graph=Calculategraph();
    int flow = maxFlow(graph, Source(), Target());
    update_report_data(mode(), m_rounds, flow);
    update_report_data(mode()+1, m_rounds, flow);
    update_report_data(mode()+2, m_rounds, flow);
    Edge* e;
    while(flow>0)
    {
        switch(mode())
        {
               case MODE_BASE_ATTACK:e=base_attack();
                      break;
               case MODE_STATIC_ATTACK:e=static_attack();
                      break;
               case MODE_REACTIVE_ATTACK:e=react_attack();
                      break;
        }
        update_report_data(mode(), m_rounds, flow);
        update_report_data(mode()+1, m_rounds, flow);
        update_report_data(mode()+2, m_rounds, flow);
        flow = StaticRoutingFlow(e, flow);
    }
    write_report(mode());
    write_report(mode()+1);
    write_report(mode()+2);
}

void Controller::ReActiveRouting()
{
    int **graph=Calculategraph();
    int flow = maxFlow(graph, Source(), Target());
    update_report_data(mode(), m_rounds, flow);
    update_report_data(mode()+1, m_rounds, flow);
    update_report_data(mode()+2, m_rounds, flow);
    Edge* e;
    while(flow>0)
    {
        switch(mode())
        {
               case MODE_BASE_ATTACK:e=base_attack();
                      break;
               case MODE_STATIC_ATTACK:e=static_attack();
                      break;
               case MODE_REACTIVE_ATTACK:e=react_attack();
                      break;
        }
        graph = RemoveEdge(graph, e);
        paths.clear();
        update_report_data(mode(), m_rounds, flow);
        update_report_data(mode()+1, m_rounds, flow);
        update_report_data(mode()+2, m_rounds, flow);
        flow = maxFlow(graph, Source() , Target());
    }
    write_report(mode());
    write_report(mode()+1);
    write_report(mode()+2);
}

int ** Controller::RemoveEdge(int **graph, Edge* e)
{
    int u= e->source()->id();
    int v= e->target()->id();
    graph[u][v]=0;

    return graph;
}


int Controller::test_node_copy()
{
    parser->import(50);
    std::vector<Node> t = parser->nodes();
    return 0;
}


void Controller::write_report(short modes)
{
    auto t = time(NULL);
    std::vector<QString> reports;
    QString mode_names[3]
    {
        "base_attack",
        "static_attack",
        "react_attack"
    };

    QString file_names[9] =
    {
        "report_time_base_attack",
        "report_50_base_attack",
        "report_k_base_attack",
        "report_time_static_attack",
        "report_50_static_attack",
        "report_k_static_attack",
        "report_time_react_attack",
        "report_50_react_attack",
        "report_k_react_attack"
    };

    QString file_name = QString("%1_%2_%3.csv")
            .arg(t)
            .arg(mode_names[m_mode])
            .arg(file_names[modes]);

    QFile file(file_name);

    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(& file);
        stream << reports[modes];
        file.close();
    }
}

void Controller::update_report_data(short mode, short round, short maxFlow){
    reports[mode].append(QString("%1,%2,%3,%4\n")
                    .arg(mode)
                    .arg(round)
                    .arg(maxFlow)
                    .arg(m_kvalue));

}

void Controller::attack()
{
    nodes = parser->nodes();
    Node * s = &(nodes[nodes.size()-2]);
    Node * t = &(nodes[nodes.size()-1]);
    Source(s);
    Target(t);
    if (m_attack == MODE_STATIC_ROUTING)
    {
        QtConcurrent::run(this, Controller::StaticRouting);
    }
    else if (m_attack == MODE_REACTIVE_ROUTING)
    {
        QtConcurrent::run(this, Controller::ReActiveRouting);
    }
}
