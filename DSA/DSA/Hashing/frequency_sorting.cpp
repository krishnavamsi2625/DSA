// Time Complexity : O(n log n) + O(n) = O(n logn)
// Space Complexity : O(1)


#include <algorithm>
#include <iostream>
using namespace std;

void countDistinct(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)         
    {
        int count = 1;
        while (i < n - 1 && arr[i] == arr[i + 1]) 
        {
            i++;
            count++;
        }

        cout << arr[i] << ": " << count << endl;
    }

}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinct(arr, n);
    return 0;
}