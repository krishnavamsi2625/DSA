// Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

void countFrequency(int *arr, int size) 
{

    for (int i = 0; i < size; i++) 
    {
        int flag = 0;
        int count = 0;
        for (int j = i + 1; j < size; j++) 
		{
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;

        for (int j = 0; j <= i; j++) 
        {
            if (arr[i] == arr[j])
                count += 1;
        }

        cout << arr[i] << ": " << count << endl;
    }
}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, size);

    return 0;
}