#include <bits/stdc++.h>
using namespace std;

vector <int> getIntersection(int arr1[], int arr2[], int size1, int size2, vector<int> &result)
{
    unordered_set<int> set1;
    unordered_set<int> set2;

    /*
    method 1 of insertion:-
    for (int i = 0; i < size1; i++)
        set1.insert(arr1[i]);

    for (int i = 0; i < size2; i++)
        set2.insert(arr2[i]);*/

    
    //method 2 of insertion
    int i = 0, j = 0;
    //add elements till size1/size2, whichever is smaller
     while(i<size1 && j<size2)
	{
         set1.insert(arr1[i]);
         set2.insert(arr2[j]);
    	 i++;
         j++;
	 }

    // Optimized method to add elements to set
    // // add remaining elements of arr1, if any
    while(i<size1)
    {
         set1.insert(arr1[i]);
         i++;
    }

    // add remaining elements of arr1, if any
    while(j<size2)
    {
        set2.insert(arr2[j]);
        j++;
    }

    for (int i : set1) {
        if (set2.find(i) != set2.end())
            result.push_back(i);
    }

    return result;
}

int main()
{
    int arr1[] = {5, 8, 5, 7, 8, 10};
    int arr2[] = {1, 5, 5, 8, 1, 8, 7};
    vector <int> result;

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    getIntersection(arr1, arr2, size1, size2, result);

    for (auto x : result)
        cout << x << " ";


    return 0;
}