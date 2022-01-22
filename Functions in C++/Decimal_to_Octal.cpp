// Decimal To Octal

#include<iostream>
using namespace std;

int DecimalToOctal(int n)
{
    int ans = 0;
    int x = 1;

    while(x <= n)
    {
        x *= 8;
    }
    x /= 8;

    while( x > 0)
    {
        int lasDigit = n/x;
        n -= lasDigit * x;
        x /= 8;
        ans = ans * 10 + lasDigit;
    }    
    return ans;
}

int32_t main()
{
    int n;
    cin>>n;

    cout<<DecimalToOctal(n)<<endl;

    return 0;
}