// Return Susequence of Sring

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int subsequence(string str, string output[])
{
    if (str.empty())
    {
        output[0] = ""; // empty string
        return 1;
    }

    string smallstring = str.substr(1);
    int smalloutputSize = subsequence(smallstring, output);

    for (int i = 0; i < smalloutputSize; ++i)
    {
        output[i + smalloutputSize] = str[0] + output[i];
    }

    return 2 * smalloutputSize;
}

int main()
{
    string str;
    cin >> str;

    int n = str.length();
    n = pow(2, n);

    string *output = new string[n]; // dynamic string array

    int count = subsequence(str, output);

    for (int i = 0; i < count; ++i)
        cout << output[i] << endl;

    return 0;
}