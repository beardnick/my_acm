#include<iostream>
#include<cstdio>
using namespace std;
#define N 100000
int a[N],s[N];
void calc(int s[],int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(!i)s[i]=a[i];
        else  s[i]=s[i-1]+a[i];
    }
}
void findmax(int s[],int a[],int n,int &beg,int &en,int& maxs)
{
    maxs=s[0];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                if(s[i]>maxs)
                {
                    maxs=s[i];
                    beg=en=i;
                }
            }
            else if(s[j]-s[i]+a[i]>maxs)
            {
                maxs=s[j]-s[i]+a[i];
                beg=i;
                en=j;
            }
        }
    }
}
int main()
{
    int lin,n,cas,beg,en,maxs;
        cin>>lin;

        cas=0;
        while(lin--)
        {
            beg=en=0;
            cin>>n;
            for(int i=0;i<n;i++)cin>>a[i];
            calc(s,a,n);
            findmax(s,a,n,beg,en,maxs);
            printf("Case %d:\n",++cas);
            cout<<maxs<<' '<<beg+1<<' '<<en+1<<endl;
            if(lin!=0)cout<<endl;
        }

}
