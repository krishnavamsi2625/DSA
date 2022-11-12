#include <iostream>
#include<vector>
using namespace std;
bool isValid(vector<int>colPlacements)
{
    int rowID=colPlacements.size()-1;
    for(int i=0;i<rowID;i++)
    {
        int diff=abs(colPlacements[i]- colPlacements[rowID]);
        if(diff==0||diff==rowID-i)
        {
            return false;
        }
    }
    return true;
}
void solve(int n,int row,vector<int> colPlacements,vector<vector<int>>& result)
{
    if(n==row)
    {
        result.push_back(colPlacements);
    }
    else
    {
        for(int col=0;col<n;col++)
        {
            colPlacements.push_back(col);//make an choice
            if(isValid(colPlacements))
            {
                solve(n,row+1,colPlacements,result); //proceed in the path of choice made
            }
            colPlacements.pop_back();//undo our choice or backtrack
            
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> result;
    vector<int>colPlacements;
    solve(n,0,colPlacements,result);
    return result;
}
void printer(vector<vector<int>> ans,int n)
{
    int board=1;
    for(auto x:ans)
        {   cout<<"Board "<<board<<"\n";
            int k=0;
            for(int i=0;i<n;i++)    
            {   int f=1;
                for(int j=0;j<n;j++)
                {
                    if(j==x[k]&&f)
                    {
                        cout<<"Q ";
                        f=0;
                        k++;
                    }
                    else
                    {
                        cout<<"* ";
                    }
                }
                cout<<"\n";
            }
            board++;
        }
}
int main()
{   
    int n;
    cout<<"Enter the Board Size:- ";
    cin>>n;
    vector<vector<int>> ans=nQueens(n);
    printer(ans,n);
    return 0;
}
