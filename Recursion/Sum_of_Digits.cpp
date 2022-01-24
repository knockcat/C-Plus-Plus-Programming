// Sum of Digits

#include <iostream>
using namespace std;

int SumOfDigit(int num)
{
    if (num == 0)
        return 0;

    int ans = num % 10;
    return ans + SumOfDigit(num / 10);
}

int main()
{
    int num;
    cin >> num;

    cout << SumOfDigit(num);

    return 0;
}
