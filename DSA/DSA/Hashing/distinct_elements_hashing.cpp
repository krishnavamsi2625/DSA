// Insertion in Set : O(1)
// For n Elements : O(n),
// Total Time complexity : O(n) +O(1) => O(n) Traverse set to count distinct

#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int size)
{
    unordered_set<int> set;
    for (int i = 0; i < size; i++)
        set.insert(arr[i]);

    return set.size();
}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << countDistinct(arr, size);

    return 0;
}