// // Last index

#include <iostream>
using namespace std;

// Another Approach

/*
int LastIndex(int arr[], int size, int n)
{
    if (size == 0)
        return -1;
    if (arr[size - 1] == n)
        return size - 1;
    else
        return LastIndex(arr, size - 1, n);
}
*/

int LastIndex(int arr[], int size, int n)
{
    if (size == 0)
        return -1;

    int index = LastIndex(arr + 1, size - 1, n);

    if (index != -1)
        return index + 1;

    if (arr[0] == n)
        return 0;
    else
        return -1;
   
}

int main()
{
    int size, x;

    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << endl;
    cout << "Enter Key : " << endl;

    cin >> x;

    cout << LastIndex(arr, size, x) << endl;

    return 0;
}
