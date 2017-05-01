#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    parser = new Parser(this);
}

int Controller::test_parser()
{

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

    while(BFS(rGraph, s, t)==true)
    {
        int path_flow = 20;

        Path P=AugmentingPath(rGraph, s, t);
        addpath(P);

        for (v=t; v != s; v=v->parent())
        {
            u = v->parent();
            rGraph[u->id()][v->id()] -= P.flow();
            rGraph[v->id()][u->id()] += P.flow();
        }

        max_flow += path_flow;
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

         for (unsigned int v=0; v<parser->nodes().size(); v++)
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
