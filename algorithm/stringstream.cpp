#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    int x;
    string str;
    while(getline(cin,str))
    {
        stringstream ss(str);
        while(ss>>x)cout<<x<<endl;
    }
    return 0;
}
