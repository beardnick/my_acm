#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define N 10
int tot=0,vis[2][10],k,n;
char a[N][N];
void search(int cur,int k,int n,int c,int d)
{
    if(cur==k)
    {
        tot++;
    }
    else
    {
        for(int i=c;i<n;i++)
        {
            c=0;
            for(int j=d;j<n;j++)
        {
            d=0;
            if((!vis[0][i])&&(!vis[1][j])&&(a[i][j]=='#'))
            {
                vis[0][i]=vis[1][j]=1;
                if(j==n-1)
                {
                    search(cur+1,k,n,i+1,0);
                }

                else
                {
                    search(cur+1,k,n,i,j+1);
                }
                vis[0][i]=vis[1][j]=0;
            }
        }
        }
    }
}
int main()
{
    int n,k;
    while((cin>>n>>k)&&n!=-1&&k!=-1)
    {
        tot=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        search(0,k,n,0,0);
        cout<<tot<<endl;
    }
    return 0;
}
