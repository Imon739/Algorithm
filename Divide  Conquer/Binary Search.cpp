#include <bits/stdc++.h>

using namespace std;


int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}


int main()
{
    int arr[] = {1,3,5,7,9,11};
    int key = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, key);
    (result == -1)? cout << "Not Found" : cout << "Found at index " << result;
    return 0;
}
