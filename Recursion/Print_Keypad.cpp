// print Keypad

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string dial(int key)
{
    unordered_map<int, string> m;

    m[0] = "";
    m[1] = "";
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";

    return m[key];
}

void Print_Keypad(int num, string out)
{
    if (num == 0)
    {
        cout << out << endl;
        return;
    }

    string str = dial(num % 10);
    for (int i = 0; i < str.size(); ++i)
        Print_Keypad(num / 10, str[i] + out);
}

int main()
{
    int num;
    cin >> num;

    string output = "";

    Print_Keypad(num, output);

    return 0;
}