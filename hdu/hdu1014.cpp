#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int x,int y)
{
    int i=1;
    while(x&&y)
    {
        i=x%y;
        x=y;
        y=i;
    }
    return x;
}
int main()
{
    int step,mod;
    while(cin>>step>>mod)
    {
        int t=0;
        if(1==gcd(step,mod))printf("%11d%20d    Good Choice\n",step,mod);
        else printf("%11d%20d    Bad Choice\n",step,mod);
    }
    return 0;
}
