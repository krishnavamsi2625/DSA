#include <iostream>
#include<unordered_set>
#include<set>
using namespace std;

int main()
{   int sum=13;
    int arr1[]={10,2,15,2,9,3,4,12};
    unordered_set<int> s;
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {   if(s.find(sum-arr1[i])!=s.end())
        {
            cout<<arr1[i]<<"|"<<sum-arr1[i]<<endl;
        }
        s.insert(arr1[i]);
    }
}
