#include<iostream>
#include<cstring>
using namespace std;
int gra[100][100];
int maxtot=0;
int tot;
int n;
void sovle(int posa,int posb)
{
       maxtot=max(maxtot,tot*10+tot*(tot+1)/2);
        tot+=gra[posa][posb];
        cout<<posa<<' '<<posb<<' '<<tot<<endl;
        for(int i=1;i<=n;i++)
        {
            if(gra[posb][i]&&i!=posa&&i!=posb)
            {
                   sovle(posb,i);
                   tot-=gra[posb][i];
            }
        }
}
int main()
{
    while(cin>>n)
    {
        maxtot=0;
        tot=0;
        int x,y;
        memset(gra,0,sizeof(gra));
        for(int i=1;i<=n-1;i++)
        {
            cin>>x>>y;
            cin>>gra[x][y];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<gra[i][j]<<' ';
            cout<<endl;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)sovle(i,j);
        cout<<maxtot<<endl;
    }
    return 0;
}
