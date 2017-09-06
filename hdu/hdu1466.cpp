#include<iostream>
#include<cstdio>
using namespace std;
#define N 30
int main()
{
    int n,d[N];
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            d[i]=i*(i-1)/2;
        }
        for(int i=n;i>=1;i--)
        {
            if(i==n)cout<<0;
            else cout<<' '<<(n-i)*i+d[n-i];
        }
        cout<<endl;
    }
    return 0;
}
