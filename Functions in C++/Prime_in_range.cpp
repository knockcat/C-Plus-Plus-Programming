// print prime numbers in given number

#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int num)
{
    if(num == 1)
        return false;
    for(int i = 2; i<=sqrt(num); i++)           // i<=num/2
    {
        if(num%i == 0)
            return false;
    }
    return true;
}

int main(){
   int a , b;
   cin>>a>>b;

   for(int i = a; i <= b; i++)
   {
       if(isPrime(i))
        cout<<i<<endl;
   }

   return 0;
}

