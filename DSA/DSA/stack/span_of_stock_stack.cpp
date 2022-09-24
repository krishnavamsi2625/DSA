// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
int main() {
    // Write C++ code here
    int arr[] = {12, 14, 15, 7, 15, 17, 5};
    stack<int> s;
    s.push(0);
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        if(arr[s.top()]<=arr[i])
        {
            s.pop();
            s.push(i);
            cout<<"The span of  stock "<<arr[i]<<" is "<<i+1<<endl;
            continue;
        }
        cout<<"The span of  stock "<<arr[i]<<" is "<<i-s.top()<<endl;
    }
    

    return 0;
}