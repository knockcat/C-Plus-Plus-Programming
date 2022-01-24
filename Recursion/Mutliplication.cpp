// Multiplication Recursively 

#include<iostream>
using namespace std;

int Multiply(int a, int b)
{
    if( a < b)
        return Multiply(b,a);
    else if(b != 0)
        return (a + Multiply(a,b-1));
    else
        return 0;
}

int main()
{
    int a, b;
    cout << "Enter 2 Numbers : ";
    cin >> a >> b;

    cout << Multiply(a,b);

    return 0;
}