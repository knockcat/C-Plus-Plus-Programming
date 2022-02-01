// Merge Sort

#include <iostream>
using namespace std;

void Merge(int arr[], int lb, int mid, int ub)
{
    int b[ub];

    int i = lb, j = mid + 1, k = lb;

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            ++i;
        }
        else
        {
            b[k] = arr[j];
            ++j;
        }
        ++k;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            ++j;
            ++k;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            ++i;
            ++k;
        }
    }

    for (int k = lb; k <= ub; k++)
        arr[k] = b[k];
}

void Merge_Sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        Merge_Sort(arr, lb, mid);
        Merge_Sort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Merge_Sort(arr, 0, n - 1);
   
    print(arr, n);
    return 0;
}