#include<iostream>
#include<algorithm>
using namespace std;
int a[1100],dp[1100];
int main()
{
    int n,res=0;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
            }
        }
        for(int i=0;i<n;i++)res=max(res,dp[i]);
        cout<<res<<endl;
    }
    return 0;
}
