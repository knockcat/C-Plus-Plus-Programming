// Decimal To Hexadecimal

#include<iostream>
#include<string>
using namespace std;

string DecimalToHexadecimal(int n)
{
    string ans = "";
    int x = 1;

    while(x <= n)
    {
        x *= 16;
    }
    x /= 16;

    while( x > 0)
    {
        int lasDigit = n/x;
        n -= lasDigit * x;
        x /= 16;
        if(lasDigit < 9)
            ans += to_string(lasDigit);
        else
        {
            char c = 'A' + lasDigit - 10;
            ans.push_back(c);
        }
    }    
    return ans;
}

int32_t main()
{
    int n;
    cin>>n;

    cout<<DecimalToHexadecimal(n)<<endl;

    return 0;
}