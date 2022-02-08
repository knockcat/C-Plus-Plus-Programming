// Print Subsequences

#include <iostream>
#include <string>
using namespace std;

void print_subsequence(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    print_subsequence(input.substr(1), output);            // removed str[0]
    print_subsequence(input.substr(1), output + input[0]); // include str[0]
}

int main()
{
    string str;
    cin >> str;

    string output = "";

    print_subsequence(str, output);

    return 0;
}