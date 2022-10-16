

#include <iostream>
#include<vector>
#include<climits>
using namespace std;
class Graph
{   
    public:
    int v;
    vector<vector<int>> graph;
    Graph(int v);
    void newEdges(int weight,int v1,int v2);
    int minFind(int *weight,int *visited);
    void primPrint(int *weight,int src);
    void dijkstra( int src);
};
Graph::Graph(int v)
{
    this->v=v;
    graph.resize(v);
    for(int i=0;i<v;i++)
    {
        graph[i].resize(v,0); 
    }
}
void Graph::newEdges(int weight,int v1,int v2)
{
    graph[v1][v2]=weight;
    graph[v2][v1]=weight;
}
int Graph::minFind(int *weight,int *visited)
{
    int index=-1;
    int min=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(weight[i]<=min && !visited[i])
        {
            index=i;
            min=weight[i];
        }
    }
    return index;
}
void Graph::dijkstra(int src)
{
    
    int weight[v];
    int visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        weight[i]=INT_MAX;
    }
    weight[src]=0;
    int curr;
    for(int count=0;count<v-1;count++)
    {
        curr=minFind(weight,visited);
        //cout<<curr<<endl;
        visited[curr]=1;
        for(int i=0;i<v;i++)
        {   
            if(graph[curr][i]&&!visited[i] &&weight[curr]!=INT_MAX&&graph[curr][i]+weight[curr]<weight[i])
            {   

                weight[i]=graph[curr][i]+weight[curr];
            }
        }
        
    }
    primPrint(weight,src);
}
void Graph::primPrint(int *weight,int src)
{   
    cout<<"Source  Edge  cost\n";
    int sum=0;
    for(int i=0;i<v;i++)
    {   sum+=weight[i];
        cout<<"  "<<src<<"  =>  "<<i<<"  =   "<<weight[i]<<"\n";
    }
    //cout<<""<<"Minimum cost= "<<sum;
}

int main()
{
    Graph g(8);
    // g.newEdges(9,0,1); //0->1 & 1->0
    // g.newEdges(1,0,5); //0->5 & 5->0
    // g.newEdges(4,1,2); //1->2 & 2->1 
    // g.newEdges(3,1,6); //1->6 & 6->1 
    // g.newEdges(2,2,3); //2->3 & 3->2
    // g.newEdges(6,3,4); //3->4 & 4->3
    // g.newEdges(5,3,6); //3->6 & 6->3
    // g.newEdges(8,4,5); //4->5 & 5->4
    // g.newEdges(7,4,6); //4->6 & 6->4 
   g.graph= {
             { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
             { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
             { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
             { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
             { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
             { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
             { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
             { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
             { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
        
    };
    g.dijkstra(0);
    
    return 0;
}
