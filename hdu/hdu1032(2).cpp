#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1000010];
int calc(int n)
{
    int counter=1;
   while(n!=1)
   {
       if(n%2==0)n/=2;
       else n=3*n+1;
       counter++;
   }
   return counter;
}
int main()
{
    int x,y;
    while(cin>>x>>y)
    {

        int maxx=1,maxn=1,k=x;
        int x1=min(x,y),y1=max(x,y);
        for(int i=x1;i<=y1;i++)a[i]=calc(i);
        for(int i=x1;i<=y1;i++)
            if(a[i]>maxx)
                maxx=a[i];
        printf("%d %d %d\n",x,y,maxx);
    }
    return 0;
}
