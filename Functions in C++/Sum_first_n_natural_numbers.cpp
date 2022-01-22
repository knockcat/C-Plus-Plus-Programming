// Sum of first n natural numbers

// 1 + 2 + 3 + 4 + . . . . . . . . . . . . . . .n

#include<iostream>
using namespace std;

int Sum_series(int n)
{
    return n*(n + 1) / 2;
}

int main()
{
    int n,sum;
    cin>>n;
    
    sum = Sum_series(n);

    cout<<sum;
}
