/*
Rule 1: 1->can visit
Rule 2: 0->Obstacle
Rule 3: one path can be visited only once
Rule 4: The rat can move in all directio
*/
#include <bits/stdc++.h>
using namespace std;
int N;
 
bool IsValid(vector<vector<int>> maze,int x,int y)
{
  if(x>=0&&x<N&&y>=0&&y<N)//checking for out of bond
  if(maze[x][y])//checking if path is allowed 
  return true;
 
  return false;
}
 
void PrintSolution(vector<vector<int>> sol)
{
  for(int i=0;i<N;i++){
  for(int j=0;j<N;j++)
  cout<<sol[i][j]<<" ";
  cout<<endl;
  }
}
 
bool solveMazeUtil(vector<vector<int>> maze,int x,int y,vector<vector<int>> &sol)
{
    if(x==N-1&&y==N-1) //base case or destination
    {
        if(maze[x][y]==1) 
        {
            sol[x][y]=1;
            return true;
        
        }
    }
    if(IsValid(maze,x,y))//checking for valid path
        {
            if(sol[x][y]) //Checking for already visited; 
            {
                return false;
            }
            sol[x][y]=1;
            if(solveMazeUtil(maze,x+1,y,sol))
            {
                return true;
            }
            if(solveMazeUtil(maze,x,y+1,sol)) 
            {
                return true;
            }
            if(solveMazeUtil(maze,x-1,y,sol)) 
            {
                return true;
            }
            if(solveMazeUtil(maze,x,y-1,sol))
            {
                return true;
            }
            sol[x][y]=0;//undo or trace back the path
            return false;
        }
    return false;
}
 
int main()
{
  N=5;
  vector<vector<int>> maze(N,vector<int>(N,1));
  vector<vector<int>> sol(N,vector<int>(N,0));
  maze[1][1]=0;maze[1][2]=0;maze[3][4]=0;maze[2][3]=0;
  maze[3][0]=0;maze[4][1]=0;
  cout<<"The maze is as follows:"<<endl;
  PrintSolution(maze);
  cout<<endl;
  if(solveMazeUtil(maze,0,0,sol))
  {
      cout<<"The solution is:"<<endl;
      PrintSolution(sol);
      
  }
  else cout<<"Solution not possible";
}