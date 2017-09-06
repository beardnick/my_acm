#include<iostream>
#include<cstring>
using namespace std;
#define N 40
char a[N][N];
int tot=1,d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void solve(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        if(a[x+d[i][0]][y+d[i][1]]=='.')
        {
           // cout<<250<<endl;
            tot++;
           // cout<<tot<<endl;
            a[x+d[i][0]][y+d[i][1]]='#';
            solve(x+d[i][0],y+d[i][1]);
        }
    }
}
int main()
{

    int h,w;
    while(cin>>h>>w&&h&&w)
    {
        tot=1;
        int be,en;
        for(int i=0;i<=w+1;i++)
        for(int j=0;j<=h+1;j++)
            a[i][j]='#';

        for(int i=1;i<=w;i++)
        {
            for(int j=1;j<=h;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='@'){be=i;en=j;}
            }
        }

//                for(int i=0;i<=w+1;i++)
//        {
//            for(int j=0;j<=h+1;j++)
//                cout<<a[i][j];
//            cout<<endl;
//        }
            solve(be,en);
        cout<<tot<<endl;

    }
    return 0;
}
