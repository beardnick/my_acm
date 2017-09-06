#include<iostream>
#include<string.h>
using namespace std;
#define N 110
int b[N][N];
int main()
{
    int m,n,a[2][N];
    while(cin>>m>>n)
    {
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        cin>>a[0][i]>>a[1][i];
    for(int i=0;i<n;i++)
    {
        b[a[0][i]-1][i]=1;
        b[a[1][i]-1][i]=-1;
    }
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<n;j++)
        {
            if(0==j)cout<<b[i][j];
            else cout<<' '<<b[i][j];
        }
        cout<<endl;
    }
    }
    return 0;
}
