// Remove Duplicates

#include <iostream>
#include <string>

using namespace std;

string Remove_duplicates(string s)
{
    if (s.length() <= 1)
        return s;
    string Smallstring = Remove_duplicates(s.substr(1));
    if (Smallstring[0] == s[0])
        return Smallstring;
    else
        return s[0] + Smallstring;
}

int main()
{
    string s;
    cin >> s;

    cout << Remove_duplicates(s);

    return 0;
}