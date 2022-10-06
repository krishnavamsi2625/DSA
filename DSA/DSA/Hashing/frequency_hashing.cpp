// Time Complexity : O(1)+O(n)=> O(n)
// Space Complexity : O(1)


#include <unordered_map>
#include <iostream>
using namespace std;

void countDistinct(int arr[], int n)
{
    unordered_map<int,int> count;
    for (int i = 0; i < n; i++)         
    {   count[arr[i]]++;
    }
    cout<<"\tAny order:-"<<endl;
    for(auto itr:count)
    {
        cout<<"\t"<<itr.first<<":"<<itr.second<<endl;
        
    }
    cout<<"\tInserted Order:-"<<endl;
    for (int i = 0; i < n; i++) 
    {
        if (count[arr[i]] != -1) 
        {
            cout << "\t"<<arr[i] << ": " << count[arr[i]] << endl;
            count[arr[i]] = -1;
        }
    }

}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinct(arr, n);
    return 0;
}