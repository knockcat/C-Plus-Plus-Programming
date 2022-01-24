// Check Palindrome

#include<iostream>
#include<string>
using namespace std;

bool IsPalindrome(string s, int i)
{
    if(i > s.size()/2)
        return true;
    return s[i] == s[s.length()-i-1] && IsPalindrome(s,i+1);
}

int main()
{
    string s;
    cin>>s;

    if(IsPalindrome(s,0) == true)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not a Palindrome"<<endl;

    return 0;
}