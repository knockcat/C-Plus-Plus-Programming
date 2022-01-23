// First Index

#include <iostream>
using namespace std;

int ArrIndex(int arr[],int size,int n)
{
    if(size == 0)
        return -1;
    if(arr[0] == n)
        return 0;
    int index = ArrIndex(arr+1, size -1, n);
    if(index != -1)
        return index + 1;
    return index;
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

    cout<< ArrIndex(arr, size, x)<<endl;

    return 0;
}
