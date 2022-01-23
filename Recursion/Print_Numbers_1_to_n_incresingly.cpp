// Print Numbers 1 to n incresing order Recursively

#include <iostream>
using namespace std;

void Print(int n)
{
    if (n > 0)
        Print(n - 1);
    else
        return;

    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    Print(n);
    return 0;
}