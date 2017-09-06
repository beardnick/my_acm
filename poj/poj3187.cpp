#include<iostream>
#include<algorithm>
using namespace std;
int n,sum,a[20];
int f[200];
int calc();
void vis();
int c(int x,int y);
int main()
{
    f[1]=f[0]=1;
    for(int i=2;i<=20;i++)
        f[i]=f[i-1]*i;
     for(int i=0;i<20;i++)
        a[i]=i+1;
   //for(int i=0;i<12;i++)cout<<c(i,11)<<endl;
    while(cin>>n>>sum)
    {
        vis();
        for(int i=0;i<n;i++)
        {
            if(i==0)cout<<a[0];
            else cout<<' '<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
int calc()
{
    int sum=0;
    for(int i=0;i<=n-1;i++)
    {
        sum=sum+c(i,n-1)*a[i];
    }
    return sum;
}
void vis()
{
         for(;;)
    {
        if(calc()==sum)break;
        else next_permutation(a,a+n);
    }
}
int c(int x,int y)
{
    return f[y]/(f[y-x]*f[x]);
}
