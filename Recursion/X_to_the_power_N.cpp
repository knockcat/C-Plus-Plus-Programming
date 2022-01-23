// x to the power n

#include<iostream>
using namespace std;

int Power(int x , int n)
{
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    if(n>0)
        return x * Power(x, n-1);
    else
        return 1/x * Power(x, n+1);
    
}

int main()
{
    int x , n;
    cin>>x>>n;
    cout<<"x^n = "<<Power(x,n)<<endl;

    return 0;
}