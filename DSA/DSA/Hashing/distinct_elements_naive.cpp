//time complexity O(n^2)
#include <bits/stdc++.h>
using namespace std;

int countDistinct(int *array, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        int flag = 0;

        for (int j = i+1; j < size; j++) {
			if (array[i] == array[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            count++;
    }
    return count;
}
int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << countDistinct(arr, size);

    return 0;
}
