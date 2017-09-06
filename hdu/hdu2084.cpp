#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 110
int a[N][N],dp[N][N],n;
//int solve(int x,int y)
//{
//    if(x==n)return a[x][y];
//    else return dp[x][y]=max(solve(x+1,y),solve(x+1,y+1))+a[x][y];
//}
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        cin>>n;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=i;j++)
                cin>>a[i][j];
       }
//        for(int i=1;i<=n;i++)
//       {
//           for(int j=1;j<=i;j++)
//                cout<<a[i][j]<<' ';
//                cout<<endl;
//       }
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
                dp[i][j]=i==n?a[i][j]:max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        }
        cout<<dp[1][1]<<endl;
    }
    return 0;
}
