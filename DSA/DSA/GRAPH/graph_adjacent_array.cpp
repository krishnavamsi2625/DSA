// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
        int vertex,edges;
        int **adj;
        public:
        Graph(int edges,int vertex);
        void newEdge(int start,int e);
        void dfsUtil(int start,int &count,vector<bool>&visited);
        void dfs();
        void bfs();
        void bfsUtil(int start,bool *visited);
        bool * resetVisited()
        {
            bool * visited=new  bool[vertex];
            return visited;
        }
};
Graph::Graph(int vertex,int edges)
{
    this->edges=edges;
    this->vertex=vertex;
    adj=new int*[vertex];
    for(int i=0;i<vertex;i++)
    {
        adj[i]=new int[vertex];
        for(int j=0;j<vertex;j++)
        {
            adj[i][j]=0;
        }
    }
}
void Graph::newEdge(int v1,int v2)
{
    adj[v1][v2]=1;
    adj[v2][v1]=1;
}
void Graph::dfsUtil(int start,int &count,vector<bool>&visited)
{   
    cout<<start<<" ";
    count++;
    visited[start]=true;
    for(int i=0;i<vertex;i++)
    {
        if(count==vertex)
        {
            return;
        }
        if(adj[start][i]==1&&(!visited[i]))
        {
            dfsUtil(i,count,visited);
        }
    }
    
}
// We use  this function to even traverse Non-connected Vertex
void Graph::dfs()
{   
    vector<bool> visited(vertex,false);
    int n;
    for(int i=0;i<vertex;i++)
    {   
        if(!visited[i])
        {   n=0;
            dfsUtil(i,n,visited);
        }
    }
}
void Graph::bfsUtil(int start,bool * visited)
{
    queue <int>q;
    q.push(start);
    int temp;
    visited[start]=true;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp<<" ";
        int count=0;
        count++;
        for(int i=0;i<vertex;i++)
        {   
            if(count==vertex)
            {
                break;
            }
            if(adj[temp][i]==1 && !(visited[i]))
            {
                q.push(i);
                visited[i]=true;
            }
            
        }
    }
}
void Graph::bfs()
{
    bool * visited=resetVisited();
    
    for(int i=0;i<vertex;i++)
    {   
        if(!(visited[i]))
        {   
            bfsUtil(i,visited);
        }
    }
}
int main() 
{
    int v=9,e=8;
    Graph G(v,e);
    G.newEdge(0,1);
    G.newEdge(0,2);
    G.newEdge(1,3);
    G.newEdge(2,4);
    G.newEdge(2,6);
    G.newEdge(6,7);
    G.newEdge(3,5);
    G.newEdge(5,4);
    cout<<"DFS:- ";
    G.dfs();
    cout<<"\nBFS:- ";
    G.bfs();
    return 0;
}