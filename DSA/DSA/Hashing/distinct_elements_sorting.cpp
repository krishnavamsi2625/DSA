// Time Complexity :
// Sorting Elements : O(n log n)
// Traverse Array : To count distinct elements O(n)
// totAL time complexity : O(n log n) + O(n) = O(n log n)

#include <algorithm>
#include <iostream>
using namespace std;

int countDistinct(int arr[], int n)
{

    sort(arr, arr + n);

    // Traverse the sorted array
    int count = 0;
    for (int i = 0; i < n; i++) {

        // Move the index ahead whenever
        // you encounter duplicates
        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;

        count++;
    }

    return count;
}
int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countDistinct(arr, n);
    return 0;
}