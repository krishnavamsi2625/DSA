

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
    void prim();
    void primPrint(int * parent,int *weight);
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
    cout<<endl;
    for(int i=0;i<v;i++)
    {
        if(weight[i]<min && !visited[i])
        {
            index=i;
            min=weight[i];
        }
    }
    return index;
}
void Graph::prim()
{
    int parent[v];
    int weight[v];
    int visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    int curr;
    for(int count=0;count<v-1;count++)
    {
        curr=minFind(weight,visited);
        visited[curr]=1;
        for(int i=0;i<v;i++)
        {   
            if(graph[curr][i]&&visited[i]==0 &&weight[i]>graph[curr][i])
            {   
                parent[i]=curr;
                weight[i]=graph[curr][i];
            }
        }
        
    }
    primPrint(parent,weight);
}
void Graph::primPrint(int *parent,int *weight)
{   
    cout<<"\tparent edge  cost\n";
    int sum=0;
    for(int i=1;i<v;i++)
    {   sum+=weight[i];
        cout<<parent[i]<<"  =>  "<<i<<"  =    "<<weight[i]<<"\n";
    }
    cout<<""<<"Minimum cost= "<<sum;
}
int main()
{
    Graph g(7);
    g.newEdges(9,0,1); //0->1 & 1->0
    g.newEdges(1,0,5); //0->5 & 5->0
    g.newEdges(4,1,2); //1->2 & 2->1 
    g.newEdges(3,1,6); //1->6 & 6->1 
    g.newEdges(2,2,3); //2->3 & 3->2
    g.newEdges(6,3,4); //3->4 & 4->3
    g.newEdges(5,3,6); //3->6 & 6->3
    g.newEdges(8,4,5); //4->5 & 5->4
    g.newEdges(7,4,6); //4->6 & 6->4 
    // g.graph={          
    //             {0,9,0,0,0,1,0},
    //             {9,0,4,0,0,0,3},
    //             {0,4,0,2,0,0,0},
    //             {0,0,2,0,6,0,5},
    //             {0,0,0,6,0,8,7},
    //             {1,0,0,0,8,0,0},
    //             {0,3,0,5,7,0,0}
        
    //         };
    g.prim();
    
    return 0;
}

