#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char s[20];
    int n;
  cin>>n;
  getchar();
  while(n--)
    {
        gets(s);
        sort(s,s+strlen(s));
        do
        {
            for(int i=0;i<strlen(s);i++)cout<<s[i];
            cout<<endl;
        }while( next_permutation(s,s+strlen(s)));
    }
    return 0;
}
