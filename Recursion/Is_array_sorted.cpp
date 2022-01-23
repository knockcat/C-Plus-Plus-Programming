// Is Array Sorted

#include<iostream>
using namespace std;
bool sort(int arr[], int size){
    if(size == 0 || size == 1)
    return true;

    if(arr[0] > arr[1])
    return false;
    
    bool sortarray = sort(arr+1 , size-1);
        return sortarray;



}

int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;

    int arr[n];
    for (int i  = 0; i< n; i++)
    cin>>arr[i];

    bool a = sort(arr, n);

    if(a)
    cout<<"sorted array";
    else
    cout<<"Unsorted array";

return 0;
}