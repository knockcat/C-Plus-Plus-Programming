// Binary Search

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int start, int end, int key)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;

        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return BinarySearch(arr, start, mid - 1, key);
        else
            return BinarySearch(arr, mid + 1, end, key);
    }
    return -1;
}

int main()
{
    int arr[] = {-9,0,15,25,34,35,90,413,672,1799};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 90;

    int index = BinarySearch(arr, 0, n - 1, key);

    cout << "At Index  " << index;

    return 0;
}