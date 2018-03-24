#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
string tolow(string &s)
{
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))s[i]=tolower(s[i]);
        else s[i]=' ';
    }
    return s;
}
int main()
{
    set<string>word;
    string s;
    while(cin>>s)
    {
        string t;
        tolow(s);
        stringstream ss(s);
        while(ss>>t)
        word.insert(t);
    }
    for(set<string>::iterator t=word.begin();t!=word.end();t++)
        cout<<*t<<endl;
        return 0;
}
