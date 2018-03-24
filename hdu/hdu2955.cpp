#include<iostream>
#include<algorithm>
using namespace std;
float a[2][110];
int n;
float solve(int cur,float p)
{
    if(p==0||cur==n+1)return 0;
    else if(p>=a[1][cur])
    return max(solve(cur+1,p-a[1][cur])+a[0][cur],solve(cur+1,p));
    return 0;
}
int main()
{
    int c;
    float p;
    cin>>c;
    while(c--)
    {
        cin>>p>>n;
        for(int i=1;i<=n;i++)
            cin>>a[0][i]>>a[1][i];
        cout<<solve(1,p)<<endl;
    }
}
