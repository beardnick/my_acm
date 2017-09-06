#include<iostream>
#include<algorithm>
using namespace std;
int r,c,mintot;
void vis(int cur,int n,int m);
char a[50][50];
int main()
{
    while(cin>>r>>c)
    {
        mintot=r*c;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cin>>a[i][j];
        }
        vis(1,0,0);
        cout<<mintot<<endl;
    }
    return 0;
}
void vis(int cur,int n,int m)
{
    if(n==r-1&&m==c-1)mintot=min(mintot,cur);
    else
    {
        a[n][m]='#';
        if(a[n+1][m]=='.')
        {
            a[n+1][m]='#';
             vis(cur+1,n+1,m);
        }
        if(a[n][m+1]=='.')
        {
            a[n][m+1]='#';
            vis(cur+1,n,m+1);
        }
        if(a[n-1][m]=='.')
        {
            a[n-1][m]='#';
            vis(cur+1,n-1,m);
        }
        if(a[n][m-1]=='.')
        {
            a[n][m-1]='#';
            vis(cur+1,n,m-1);
        }
    }
}
