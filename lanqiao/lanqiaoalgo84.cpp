#include<iostream>
#include<string>
using namespace std;
int main()
{
    char s;
    while(cin>>s)
    {
        if(s>='a'&&s<='z')s-=32;
        else if(s>='A'&&s<='Z')s+=32;
        cout<<s;
    }
   return 0;
}
