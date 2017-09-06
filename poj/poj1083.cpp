#include<iostream>
#include<cstring>
using namespace std;
int a[210];
int solve()
{
    int i,t=-1,counter=0,emp=1;
    for(;;counter++)
    {
        emp=1;
    for(i=1;i<=200;i++)
    {
        if(a[i]>0)
        {
          emp=0;
          t=a[i];
          a[i]=0;
          break;
         // cout<<emp<<endl;
        }
    }
    if(emp)break;
    else
        {
        for(int j=i+1;j<=200;j++)
        {
            if(a[j]==t){t=-1;a[j]=0;}
            if(a[j]>0&&t==-1){t=a[j];a[j]=0;}
            //cout<<t<<endl;
        }
   // for(int j=1;j<=200;j++)cout<<a[j]<<' ';
    }
    }
    return counter;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(a,0,sizeof(a));
        int desk,x,y;
        cin>>desk;
      for(int i=1;i<=desk;i++)
        {
            cin>>x>>y;
            a[x]=a[y]=i;
        }
        cout<<10*solve()<<endl;
    }
    return 0;
}
