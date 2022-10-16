//Implemented using adjacency matrix and 2D Array for implementation
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
        void search(int start,int dst);
        void searchUtil(int start,int dst,vector<int>path,vector<vector<int>>&allPaths,vector<bool>&visited);
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
void Graph::searchUtil(int start,int dst,vector<int>path,vector<vector<int>>&allPaths,vector<bool>&visited)
{
    path.push_back(start);
    if(start==dst)
    {
        allPaths.push_back(path);
        visited[start]=false;
        return;
    }
    for(int i=0;i<vertex;i++)
    {   
        if(adj[start][i]==1 && !(visited[i]))
        {   visited[i]=true;
            searchUtil(i,dst,path,allPaths,visited);
        }
    }
    visited[start]=false;
}
void Graph::search(int start,int dst)
{
    vector<int>path;
    vector<vector<int>>allPaths;
    vector<bool>visited(vertex,false);
    visited[start]=true;
    searchUtil(start,dst,path,allPaths,visited);
    int c=1;
    for(auto path:allPaths)
    {
        cout<<"Path "<<c<<":= ";
        for(int v:path)
        {
            cout<<v<<"->";
        }
        c++;
        cout<<"\n";
        
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
    cout<<"\nPaths between 0 and 4 : \n";
    G.search(0,4);
    //G.search(0,4);
    return 0;
}
