#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1000010];
int calc(int n)
{
    if(n==1)return a[1]=1;
    else if(n%2==0)return a[n]=a[n/2]?a[n/2]+1:calc(n/2)+1;
    else if(3*n+1<=1000000) a[n]=a[3*n+1]?a[3*n+1]:calc(3*n+1)+1;
    else  a[n]=calc(3*n+1)+1;
}
int main()
{
    int x,y;
    for(int i=1;i<=10000;i++)
    {
        a[i]=calc(i);
    }
    while(cin>>x>>y)
    {
        int maxx=1,maxn=1,k=x;
        int x1=min(x,y),y1=max(x,y);
        for(int i=x1;i<=y1;i++)
            if(a[i]>maxx)
                maxx=a[i];
        printf("%d %d %d\n",x,y,maxx);
    }
    return 0;
}
