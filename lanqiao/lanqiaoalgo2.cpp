#include<iostream>
using namespace std;
long long lgc(int x,int y)
{
    long long r;
    while(x&&y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
long long maxz(long long n)
{
    long long res=2,flag=1;
    for(long long i=3;i<=n;i++)
    {
        flag=1;
        for(long long j=2;j*j<=i;j++)
        {
            if(0==i%j){flag=0;break;}
        }
        if(flag)res=i;
    }
    return res;
}
int main()
{
    long long n,t;
    cin>>n;
    t=maxz(n);
    cout<<t<<endl;
    if(n==t)cout<<t*(t-1)/lgc(t-1,t-2*(t-2))<<endl;
    else if(n-1==t)cout<<t*(t-1)/lgc(t-1,t+1)*(t+1)<<endl;
    else cout<<t*(n)/lgc(n-1,n)*(n-1)<<endl;
    return 0;
}
