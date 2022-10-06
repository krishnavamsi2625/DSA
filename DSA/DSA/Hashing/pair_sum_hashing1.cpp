/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<unordered_set>
#include<set>
using namespace std;

int main()
{   int sum=13;
    int arr1[]={10,2,15,2,9,3,4,12};
    unordered_set<int> s;
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {
        s.insert(arr1[i]);
    }
    for(auto x:arr1)
    {   //cout<<x<<endl;
        if(s.find(sum-x)!=s.end())
        {
            cout<<x<<"|"<<sum-x<<endl;
            s.erase(x);
        }
    }
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {
        s.insert(arr1[i]);
    }
    
}
