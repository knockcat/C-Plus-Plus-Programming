// Replace Characters Recursively

#include <iostream>
#include <string>
using namespace std;

string Replace(string str, char c1, char c2)
{
    if (str.length() == 0)
        return str;
    if (str[0] == c1 )
        return c2 +  Replace(str.substr(1), c1, c2);
    else
        return str[0] + Replace(str.substr(1), c1, c2);
}

int main()
{
    string str;
    char c1, c2;

    cin >> str;
    cin >> c1 >> c2;

    cout << Replace(str, c1, c2);

    return 0;
}