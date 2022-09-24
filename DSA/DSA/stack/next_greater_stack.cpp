#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int size) {
    stack<int> s;
    vector<int> v;
    for (int i = size-1; i > -1; i--) {
        bool flag = false;
        while(s.empty()==false && arr[s.top()]<=arr[i])
        s.pop();
        if(s.empty())
        v.push_back(-1);
        else 
        v.push_back(arr[s.top()]);
        s.push(i);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {   if(v[i]==-1)
        {
            cout<<"- ";
            continue;
        }
        cout<<v[i]<<" ";
    }
}

int main()
{
    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, size);
    return 0;
}