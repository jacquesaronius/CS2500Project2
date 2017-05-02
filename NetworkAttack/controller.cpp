#include "controller.h"
#include <vector>
#include <iostream>

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
    auto nodes = parser->nodes();
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

    for (unsigned int i = 0; i < parser->nodes().size(); i++)
    {
        graph[i]=new int[parser->nodes().size()];
        for (unsigned int k = 0; k < parser->nodes().size(); k++)
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

    parser->import();
    return 0;
}

int Controller::test_calculate_graph()
{
    int ** graph;
    parser->import();
    graph = Calculategraph();

    size_t size = parser->nodes().size();

    for (size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
            std::cout << graph[j][i] << ",";
        std::cout << std::endl;
    return 0;

}
void Controller::StaticRouting(Node * s, Node * t)
{
    int **graph=Calculategraph();
    int mode = 0;
    cin>>mode;
    cout<<endl;
    int flow = maxFlow(graph, s, t);
    cout<<flow<<endl;
    Edge* e;
    while(flow>0)
    {
        switch(mode)
        {
               case 1:e=base_attack();
                      break;
               case 2:e=static_attack();
                      break;
               case 3:e=react_attack();
                      break;
        }
        flow = StaticRoutingFlow(e, flow);
        cout<<flow<<endl;
    }
}

void Controller::ReActiveRouting(Node* s, Node * t)
{
    int **graph=Calculategraph();
    int mode = 0;
    cin>>mode;
    cout<<endl;
    int flow = maxFlow(graph, s, t);
    cout<<flow<<endl;
    Edge* e;
    while(flow>0)
    {
        switch(mode)
        {
               case 1:e=base_attack();
                      break;
               case 2:e=static_attack();
                      break;
               case 3:e=react_attack();
                      break;
        }
        graph = RemoveEdge(graph, e);
        paths.clear();
        flow = maxFlow(graph, s , t);
        cout<<flow<<endl;
    }
}

int ** Controller::RemoveEdge(int **graph, Edge* e)
{
    int u= e->source()->id();
    int v= e->target()->id();
    graph[u][v]=0;

    return graph;
}

Node* Controller::Source()
{
    Node * s;
    for(int i=0; i<50; i++)
    {

    }
    return s;
}
