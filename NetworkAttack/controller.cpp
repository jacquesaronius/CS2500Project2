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
    graph = new int*[parser->nodes().size()];
    for(auto i=parser->nodes().begin(); i!=parser->nodes().end(); i++)
    {
        graph[k]=new int[parser->nodes().size()];
        for(auto it=i->outgoing().begin(); it!=i->outgoing().end(); it++)
        {
            if(it->visited()==false)
            {
                graph[i->id()][it->target().id()]=it->capacity();
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

    for (unsigned int i = 0; i < parser->nodes().size(); i++)
    {
        graph[i]=new int[parser->nodes().size()];
        for (unsigned int k = 0; k < parser->nodes().size(); k++)
        {
             rGraph[i][k] = graph[i][k];
        }
    }

    int max_flow = 0;

    while(BFS(rGraph, s, t)==true && max_flow <=20)
    {

        Path P=AugmentingPath(rGraph, s, t);
        addpath(P);

        for (v=t; v != s; v=v->parent())
        {
            if(max_flow <= 20)
            {
            u = v->parent();
            rGraph[u->id()][v->id()] -= P.flow();
            rGraph[v->id()][u->id()] += P.flow();
            }
        }
        if(max_flow+P.flow()<20)
        {
        max_flow += P.flow();
        }
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
          if(v->incoming()[i].source().id()==v->parent()->id())
          {
              Apath.add_edge(v->incoming()[i]);
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
    for(unsigned int i=0; i<parser->nodes().size(); i++)
        parser->nodes()[i].visited(false);

     std::vector <Node*> Q;
     Q.push_back(s);
     s->visited(true);
     s->setparent(NULL);

     while (!Q.empty())
     {
         Node* u = Q.front();
         Q.pop_back();

         for (unsigned int v=0; v < parser->nodes().size(); v++)
         {
             if (parser->nodes()[v].visited()==false && rgraph[u->id()][parser->nodes()[v].id()] > 0)
             {
                 Q.push_back(&(parser->nodes()[v]));
                 parser->nodes()[v].setparent(u);
                 parser->nodes()[v].visited(true);
             }
         }
     }

     return (t->visited() == true);
}

void Controller::addpath(Path path)
{
    paths.push_back(path);
}

void Controller::react_attack(std::vector<Path> &paths) {
    short rounds = 1;
    short attack_index = paths.size() - 1;

    for (auto i = 0; i < paths.size(); i++) {

        initial_flow = paths[i][attack_index].flow();

        paths[i][attack_index].alive(0);

        update_report_data(); // need params still

        rounds ++;

        if (current_flow <= 0)
        
            i = paths.size();
    }   // end for
}   // end attack

void Controller::static_attack(std::vector<Path> &paths) {
    short rounds = 1;
    short flow = check_flow();
    short attack_index = paths.size() - 1;
    for (auto i = 0; i < paths.size(); i++) {
        paths[i][attack_index].alive(0);
        flow = flow - edge_capacity;
        update_report_data(); // need params still
        rounds ++;
        if (flow <= 0)
            i = paths.size();
    }   // end for
}   // end attack

void Controller::base_attack(std::vector<Edges> &edges) {
    short rounds = 1;
    short flow = check_flow();
    for (auto i = 0; i < edges.size(); i++) {
        edges[i].alive(0);
        flow = flow - edge_capacity;
        update_report_data(); // need params still
        rounds ++;
        if (flow <= 0)
            i = paths.size();
    }   // end for
}   // end attack

int Controller::StaticRoutingFlow(Edge e)
{
    for(auto i=paths.begin(); i!=paths.end(); i++)
    {
        for(auto it=paths.edges().begin(); it!=paths.edges().begin(); it++)
        {
            if(e==paths[*i].m_edges[it])
            {
                mflow -= paths[i].flow();
            }
        }
    }
    return mflow;
}
