// Replace pi

#include <iostream>
using namespace std;

string Replace_Pi(string s)
{
    if(s.length() == 0 || s.length() == 1)
        return s;
    string ans = Replace_Pi(s.substr(1));

    if(ans[0] == 'i' && s[0] == 'p' )
    {
        ans = "3.14" + ans.substr(1);
    }
    else
        ans = s[0] + ans;

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << Replace_Pi(s);

    return 0;
}