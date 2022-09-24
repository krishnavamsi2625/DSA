#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int size) {
    stack<int> s;
    for (int i = 0; i < size; i++) {
        bool flag = false;
        while(s.empty()==false && arr[s.top()]<=arr[i])
        s.pop();
        if(s.empty())
        cout<<"- ";
        else 
        cout<<arr[s.top()]<<" ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, size);
    return 0;
}