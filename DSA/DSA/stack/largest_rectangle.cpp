#include <bits/stdc++.h>
using namespace std;

int maxArea(int arr[], int n) {
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] >= arr[i])
                count++;
            else
                break;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[j] >= arr[i])
                count++;
            else
                break;;
        }
        int temp = count * arr[i];
        res = max(res, temp);
    }
    return res;

}

int main()
{
    int arr[] = {12, 2, 5, 4, 1, 7, 8};
    int n = 7;
    cout << "Max Area: " << maxArea(arr, n);
    return 0;
}