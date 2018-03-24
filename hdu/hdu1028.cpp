#include<iostream>
#define N 130
using namespace std;
int dp[N][N];
int main()
{
    int n;
    for(int i=1;i<=120;i++)
    {
        for(int j=1;j<=120;j++)
        {
            if(i==1||j==1)dp[i][j]=1;
            else if(i<j)dp[i][j]=dp[i][i];
            else if(i==j)dp[i][j]=1+dp[i][j-1];
            else dp[i][j]=dp[i-j][j]+dp[i][j-1];
        }
    }
//    for(int i=1;i<=120;i++)
//    {
//        for(int j=1;j<=i;j++)
//        {
//           cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    while(cin>>n)
        cout<<dp[n][n]<<endl;
    return 0;
}
