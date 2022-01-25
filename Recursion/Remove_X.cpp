// Remove X

#include <iostream>
using namespace std;

string Remove_X(string s)
{
    if (s.length() == 0)
        return s;
    if (s[0] == 'x' || s[0] == 'X')
        return Remove_X(s.substr(1));
    else
        return s[0] + Remove_X(s.substr(1));
}

int main()
{
    string s;
    cin >> s;
    cout << Remove_X(s);

    return 0;
}