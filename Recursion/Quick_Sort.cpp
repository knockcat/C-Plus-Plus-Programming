// Quick Sort

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int cnt = 0;
    for (int i = start + 1; i <= end; ++i)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    int pivotPos = start + cnt;
    swap(&arr[start], &arr[pivotPos]);

    int i = start;
    int j = end;

    while (i < pivotPos && j > pivotPos)
    {
        if (arr[i] <= arr[pivotPos])
            ++i;
        else if (arr[j] > pivotPos)
            --j;
        else
        {
            swap(&arr[i], &arr[j]);
            ++i;
            --j;
        }
    }
    return pivotPos;
}

void QuickSort(int arr[], int lb, int ub)
{
    if (lb >= ub)
        return;

    int pivot = partition(arr, lb, ub);
    QuickSort(arr, 0, pivot - 1);
    QuickSort(arr, pivot + 1, ub);
}

void print(int arr[], int n)
{
    int i;
    printf("\n\nArray after Sorting\n\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

int main()
{
    int arr[] = {3, 523, 135, 53, 76, 87, 0, -43, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\n\nElements in the Array\n\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    QuickSort(arr, 0, n - 1);

    print(arr, n);

    return 0;
}