// Number of Digits in a Number

#include<iostream>
using namespace std;

int NumberOfDigit(int n)
{
    static int cnt = 0;

    if(n > 0)
    {
        cnt += 1;
        return NumberOfDigit(n/10);
    }
    else
        return cnt;
}

int main()
{
    int n;
    cin>>n;
    cout<<NumberOfDigit(n)<<endl;

    return 0;
}