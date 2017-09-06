#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
void reve(int be,int en,string& s)
{
    //cout<<be<<' '<<en<<endl;
    for(int i=be;i<((en+be)/2);i++)
        swap(s[i],s[en-1-i+be]);
}
int main()
{
    string s;
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        s.clear();
        getline(cin,s);
        int be=0,en=0;
        for(int i=1;s[i]!='\0';i++)
        {
            if(' '==s[i]&&s[i-1]!=' ')
            {
                en=i;
                reve(be,en,s);
            }
        else if(s[i+1]=='\0')
           {
                en=i+1;
                reve(be,en,s);
           }
        if(' '==s[i]&&s[i+1]!=' ')be=i+1;
        }
        cout<<s<<endl;
//        for(int i=0;i<s.size();i++)
//            printf("%d ",s[i]);
//        cout<<endl;
    }
    return 0;
}
