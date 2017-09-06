#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10010][10],dp[10010][10];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int maxt=0;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        int t,p;
        scanf("%d%d",&t,&p);
        maxt=max(t,maxt);
        a[t][p]++;
        for(int i=0;i<=maxt;i++)
        {
            for(int j=0;j<=10;j++)
            {
                if(i==0)dp[i][5]=max(a[i+1][5],max(a[i+1][6],a[i+1][4]));
                    {

                    }

                else
                    if(j==0)dp[i][j]=
                    else if(j==10)
                    else
            }
        }
    }
}
