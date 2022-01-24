// Count Zeroes

#include <iostream>
using namespace std;

int Count_Zeroes(int num)
{
    static int count = 0;
    if (num > 0)
    {
        if(num % 10 == 0)
            count++;
        return Count_Zeroes(num / 10);
    }
    
    return count;
}

int main()
{
    int a;
    cin >> a;

    cout << Count_Zeroes(a);

    return 0;
}
