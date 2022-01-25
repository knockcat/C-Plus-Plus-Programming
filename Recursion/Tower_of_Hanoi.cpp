#include<iostream>
using namespace std;
//exponential time complexity  O(2^n) - 1           -> O(2^n)
void toh(int n, char a , char b, char c)
{
    if(n == 1)
    {
        cout<<"move "<<a<<" to "<<b<<endl;
    }

    else
    {
        toh(n-1, a , c, b); //move 2 (n-1) discs from a to b using c // fr n = 3
        cout<<"move "<<a<<" to "<<b<<endl;

        toh(n-1, b , a, c);
        return ;
    }
}

int main()
{
    char a = 'A' , b = 'B' , c = 'C';
    int n;

    cout<<"Enter no of towers you wnat to move from source a to b : "<<endl;
    cin>>n;

    toh(n,a,b,c);
    return 0;
}