// Check if no. exist in array recursively

#include <iostream>
using namespace std;

bool Check(int arr[], int size, int x)
{
    if (size == 0)
        return false;
    else
    {
        if (arr[size] == x)
            return true;
        else
            Check(arr, size - 1, x);
    }
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
    if (Check(arr, size, x))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}