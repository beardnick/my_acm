#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int r,c,mintot,ex,ey,sx,sy;
void vis(int cur,int n,int m);
char a[110][110];
int main()
{
    cin>>r;
    while(r--)
    {
        cin>>c;
        mintot=0;
        memset(a,'#',sizeof(a));

//        for(int i=0;i<=c+1;i++)
//        {
//            for(int j=0;j<=c+1;j++)
//                cout<<a[i][j];
//                cout<<endl;
//        }
        for(int i=1;i<=c;i++)
        {
            for(int j=1;j<=c;j++)
                cin>>a[i][j];
        }
        cin>>sx>>sy>>ex>>ey;
        if(a[sx][sy]=='#'||a[ex][ey]=='#')cout<<"NO"<<endl;
        else
        {
            vis(1,sx+1,sy+1);
        if(mintot)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    }
    return 0;
}
void vis(int cur,int n,int m)
{
    if(n==ex+1&&m==ey+1)mintot=1;
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
