//nCr

#include<iostream>
using namespace std;

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int main()
{
    int n ,r;
    cin>>n>>r;

    int ans = fact(n) / (fact(r) * fact(n-r));

    cout<<ans<<endl;
}