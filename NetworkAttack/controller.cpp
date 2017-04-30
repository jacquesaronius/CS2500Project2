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
    graph = new int*[m_nodes.size()];
    for(auto i=m_nodes.begin(); i!=m_nodes.end; it++)
    {
        graph[i]=new int[m_nodes.size()];
        for(auto it=i.m_outgoing.begin(); it!=i.outgoing.end(); it++)
        {
            if(it.visited()==false)
            {
                graph[i.id()][it.target().id()]=capacity();
            }
        }
    }
    return graph;
}

int Controller::maxFlow(int **, Node* s, Node *t)
{
    Node u, v;

    int rGraph[m_nodes.size()][m_nodes.size()];

    for (int i = 0; i < nodes.size(); i++)
        for (int k = 0; k < nodes.size(); k++)
             rGraph[i][k] = graph[i][k];

    int max_flow = 0;

    while (bfs(rGraph, s, t))
    {
        int path_flow = 20;

        path P=AugmentingPath(rGraph, s, t);

        for (v=t; v != s; v=v.getparent())
        {
            u = v.getparent();
            rGraph[u.m_id][v.m_id] -= P.flow();
            rGraph[v.m_id][u.m_id] += P.flow();
        }

        max_flow += path_flow;
    }
    return max_flow;
}

path Controller::AugmentingPath(int Graph[m_nodes.size()][m_nodes.size()], Node* s, Node* t)
{
    path Apath;
    Node u, v;
    int path_flow = 20;
    for (v=t; v!=s; v=v.parent())
    {
        u = v.parent();
        path_flow = min(path_flow, Graph[u.m_id][v.m_id]);
    }

    Apath.flow(path_flow);
    return Apath;
}

bool Controller::bfs(int **, Node* s, Node* t)
{
    for(int i=0; i<m_nodes.size(); i++)
         m_nodes[i].setvisited(false);

     vector <Node*> Q;
     Q.push(s);
     s.setvisited(true);
     s.setparent(NULL);

     while (!Q.empty())
     {
         int u = Q.front();
         Q.pop();

         for (int v=0; v<m_nodes.size(); v++)
         {
             if (m_nodes[v].visited==false && rGraph[u.m_id][v.m_id] > 0)
             {
                 q.push(m_nodes[v]);
                 v.setparent[u];
                 v.visited(true);
             }
         }
     }

     return (visited[t] == true);
}
