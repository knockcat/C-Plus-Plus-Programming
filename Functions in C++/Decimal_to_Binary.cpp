// Decimal To Binary

#include<iostream>
using namespace std;

int DecimalToBinary(int n)
{
    int ans = 0;
    int x = 1;

    while(x <= n)
    {
        x *= 2;
    }
    x /= 2;

    while( x > 0)
    {
        int lasDigit = n/x;
        n -= lasDigit * x;
        x /= 2;
        ans = ans * 10 + lasDigit;
    }    
    return ans;
}

int32_t main()
{
    int n;
    cin>>n;

    cout<<DecimalToBinary(n)<<endl;

    return 0;
}