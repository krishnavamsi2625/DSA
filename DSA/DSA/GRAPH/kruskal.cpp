// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define edge pair<int,int>
using namespace std;
class Graph
{   
    
    vector<pair<int,edge>> G;
    vector<pair<int,edge>> MST;
    int *parent;
    int v;
    public:
        Graph(int v);
        void newEdge(int weight,int v1,int v2);
        int parent_find(int i);
        void parent_set(int u,int v);
        void kruskal();
        void mstPrint();
       
    
};
Graph::Graph(int v)
{
    this->v=v;
    parent=new int[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
}
void Graph::newEdge(int weight,int v1,int v2)
{
    G.push_back(make_pair(weight,edge(v1,v2)));
}
int Graph::parent_find(int i)
{
            if(parent[i]==i)
            {
                return i;
            }
            else 
            {
                parent_find(parent[i]);
            }
        }
void Graph::parent_set(int u,int v)
{
    parent[u]=parent[v];
}
void Graph::kruskal()
{
    sort(G.begin(),G.end());
    int upr,vpr,cost=0;
    for(int i=0;i<v;i++)
    {   
        upr=parent_find(G[i].second.first);
        vpr=parent_find(G[i].second.second);
        if(upr!=vpr)
        {
            MST.push_back(G[i]);
            parent_set(upr,vpr);
        }
    }
}
void Graph::mstPrint()
{   
    int cost=0;
    if(MST.size()==0)
    {
        kruskal();
    }
    cout<<"Edge\tEdge\tCost\n";
    for(pair<int,edge>x:MST)
    {   cout<<x.second.first<<"\t-> \t"<<x.second.second<<"\t=\t"<<x.first<<"\n";
        cost+=x.first;
    }
    cout<<"The Min cost required to connect all nodes = "<<cost;
    
}
int main() 
{
    // Write C++ code here
    Graph g(6);
    g.newEdge(3,0,2);
    g.newEdge(1,0,1);
    g.newEdge(4,1,2);
    g.newEdge(11,1,3);
    g.newEdge(10,1,5);
    g.newEdge(12,2,4);
    g.newEdge(5,2,5);
    g.newEdge(2,4,5);
    g.newEdge(6,3,5);
    g.kruskal();
    g.mstPrint();
    return 0;
}