// Pair Star

#include <iostream>
using namespace std;

string Pair_Star(string s)
{
    if (s.length() == 1)
        return s;
    string ans = Pair_Star(s.substr(1));
    if (s[0] == ans[0])
        return s[0] + "*" + ans ;
    else
        return s[0] + ans;
}

int main()
{
    string s;
    cin >> s;
    cout << Pair_Star(s);
    return 0;
}
