#include<iostream>
using namespace std;
#define N 110
char a[N][N];
int m,n,tot=0;
void search(int c,int d);
void vis()
{
    for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]=='W'){search(i,j); tot++;}
//                for(int i=1;i<=n;i++)
//                {
//                      for(int j=1;j<=m;j++)
//                        cout<<a[i][j];
//                        cout<<endl;
//                }
            }
}
void search(int c,int d)
{
    a[c][d]='*';
    for(int i=c-1;i<=c+1;i++)
        for(int j=d-1;j<=d+1;j++)
            if(a[i][j]=='W'){a[i][j]='*';search(i,j);}
}

int main()
{
    while(cin>>n>>m&&n&&m)
    {
        tot=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        vis();
        cout<<tot<<endl;
    }
    return 0;
}
