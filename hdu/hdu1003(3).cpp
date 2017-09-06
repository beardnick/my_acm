#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
int a[N],s[N];
void calc(int s[],int a[],int n)
{
    s[0]=0;
    for(int i=0;i<n;i++)
    {
        s[i+1]=s[i]+a[i];
    }
}
int findmax(int s[],int n)
{
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>s[k])k=i;
    }
    return k;
}
int findmin(int s[],int n)
{
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]<s[k])k=i;
    }
    return k;
}
int main()
{
    int lin,n,cas,beg,en,maxs,mins,maxa;
        cin>>lin;
        cas=0;
        while(lin--)
        {
            beg=en=0;
            maxs=mins=maxa=0;
            cin>>n;
            for(int i=0;i<n;i++)cin>>a[i];
            calc(s,a,n);
            maxs=findmax(s,n);
            mins=findmin(s,maxs);
            maxa=findmax(a,n-1);
            if(s[maxs]-s[mins]+a[mins]>=a[maxa])
            {
                beg=mins;
                en=maxs;
            }
            else beg=en=maxa;
            printf("Case %d:\n",++cas);
            if(beg==en)
            cout<<a[maxa]<<' '<<beg+1<<' '<<en+1<<endl;
            else  cout<<s[maxs]-s[mins]<<' '<<beg+1<<' '<<en<<endl;
            if(lin!=0)cout<<endl;
        }
}
