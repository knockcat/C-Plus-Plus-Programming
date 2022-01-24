// Geometric Sum

#include<iostream>
#include<math.h>
using namespace std;

float Geometric_Sum(int k)
{
    if(k == 0)
        return 1;
    double ans = Geometric_Sum(k - 1);
    return ans +(1/pow(2,k));
    
}

int main()
{
    int k;
    cin >> k;

    cout<<Geometric_Sum(k);

    return 0;
}