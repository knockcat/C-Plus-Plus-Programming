// All Indices of Element

#include <iostream>
using namespace std;

// Another Approach

/*
int AllIndexesRecursive(int input[], int size, int x, int output[])
{

    if (size == 0)
        return 0;

    int smallAns = AllIndexesRecursive(input, size - 1, x, output);

    if (input[size - 1] == x)
    {
        output[smallAns++] = size - 1;
    }
    return smallAns;
}
*/

int AllIndexesRecursive(int arr[], int size, int x, int output[])
{
    if (size == 0)
    {
        return 0;
    }
    int ans = AllIndexesRecursive(arr + 1, size - 1, x, output);

    if (arr[0] == x)
    {
        for (int i = ans - 1; i >= 0; i--)
            output[i + 1] = output[i] + 1;

        output[0] = 0;
        ans++;
    }
    else
    {
        for (int i = ans - 1; i >= 0; i--)
            output[i] = output[i] + 1;
    }
    return ans;
}

void AllIndexes(int input[], int n, int x)
{
    int output[n];
    int size = AllIndexesRecursive(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
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

    AllIndexes(arr, size, x);

    return 0;
}
