#include <bits/stdc++.h>
using namespace std;
 
bool checkForSorting(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]-arr[i+1]>0)
        {
            if(arr[i]-arr[i+1]==1){}
 
            else return false;
        }
    }
    return true;
}