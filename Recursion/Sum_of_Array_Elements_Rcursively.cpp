// Sum of Array Elements Rcursively

#include<iostream>
using namespace std;

int Sum(int arr[], int n)
{
    if(n <= 0)
        return 0;

    return Sum(arr,n-1) + arr[n-1];
}

int main()
{
    int arr[6] = {3,45,2,3,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Sum(arr,n)<<endl;
 
    return 0;
}