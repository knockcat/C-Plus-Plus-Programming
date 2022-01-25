// String To Integer

#include<iostream>
#include<math.h>
using namespace std;

int String_To_int(string s)
{
    if(s.length() == 1)
        return s[0] - '0';
    int ans = String_To_int(s.substr(1));
    int x = s[0] = '0';
    x = x*(int)pow(10,s.length() - 1) + ans;
    return x;
}

int main()
{
    string s;
    cin >> s;
    cout<<String_To_int(s);
    return 0;
}