#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define N 100000
#define M 2
int a[N], s[M][N],b[N];
void calc(int s[M][N],int a[N],int n,int flag)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=i;j<n;j++)
        {
            if(flag==1)
            {
                 if(j==i)s[i][j]=a[i];
                if(i==0&&j!=0)s[i][j]=s[i][j-1]+a[j];
            }
            else
            {
                if(i==0&&j!=0)s[i][j]=b[i]-a[i-1];
            }

            if(i>0&&j!=i)s[i][j]=s[i-1][j]-a[i-1];
        }
    }
}
void findmax(int s[M][N],int&beg,int &en,int n,int &maxs)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i][j]>maxs)
            {
                maxs=s[i][j];
                beg=i;
                en=j;
            }
        }
    }
}
void moveto(int s[M][N],int a[N],int n)
{
    for(int i=0;i<n;i++)a[i]=s[0][i];
}
int main()
{
    int lin,cas,n,beg,en,maxs;
    while(cin>>lin)
    {
        cas=0;
        beg=en=0;
//        memset(s,0,sizeof(s));
//        memset(a,0,sizeof(a));
        while(lin--)
        {
            cin>>n;
            for(int i=0;i<n;i++)cin>>a[i];
            maxs=a[0];
            for(int i=1;i<=n-1;i++)
            {
                calc(s,a,n,i);
                findmax(s,beg,en,n,maxs);
                moveto(s,b,n);
            }
            printf("Case %d:\n",++cas);
            cout<<maxs<<' '<<beg+1<<' '<<en+1<<endl;
            if(lin!=0)cout<<endl;
        }
    }
}
