//time o(n2)
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int arr[] = {12, 14, 15, 7, 15, 17, 5};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        int c=0;
        for(int j=i;j>-1;j--)
        {
            if(arr[i]<arr[j])
            break;
            c++;
        }
        cout<<"The span of stock of "<<arr[i]<<" is "<<c<<endl;
    }

    return 0;
}