// Check AB

#include <iostream>
#include <string>
using namespace std;

bool Check_AB(string str)
{
    if(str.length() == 0)
        return true;
    
    if(str[0] == 'a')
    {
        if(str.substr(1).length() > 1 && str.substr(1,3) == "bb")
        {
            return Check_AB(str.substr(3));
        }
        else
        {
            return Check_AB(str.substr(1));
        }
    }
    return false;
}

int main()
{
    string str;
    cin >> str;
    
    if(Check_AB(str))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}
