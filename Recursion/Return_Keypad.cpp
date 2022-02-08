// Return Keypad

#include <iostream>
#include <string>
using namespace std;

int String_keypad(int n, string output[])
{
    string input;

    if (n == 0)
    {
        output[0] = "";
        return 1;
    }

    int num = n % 10;
    n = n / 10;

    int smalloutputSize = String_keypad(n, output); // recursive call

    switch (num)
    {
    case 2:
        input = "abc";
        break;
    case 3:
        input = "def";
        break;
    case 4:
        input = "ghi";
        break;
    case 5:
        input = "jkl";
        break;
    case 6:
        input = "mno";
        break;
    case 7:
        input = "pqrs";
        break;
    case 8:
        input = "tuv";
        break;
    case 9:
        input = "wxyz";
        break;
    }

    int ans_size = smalloutputSize * (input.size());

    string temp[ans_size];

    int k = 0;

    for (int i = 0; i < smalloutputSize; ++i)
    {
        for (int j = 0; j < input.size(); ++j)
            {
                temp[k] = output[i] + input[j];
                ++k;
            }
    }

    for (int i = 0; i < ans_size; ++i)
        output[i] = temp[i];

    return input.size() * smalloutputSize;
}

int main()
{
    int n;
    cin >> n;

    string *output = new string[n]; // dynamic string array

    int count = String_keypad(n, output);

    for (int i = 0; i < count; ++i)
        cout << output[i] << endl;

    return 0;
}