#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[30],n,tot=0;
int prime(int x)
{
    for(int i=2;i*i<=x;i++)
    if(x%i==0)return 0;
    return 1;
}
void prime_circle(int cur)
{
    if(cur==n)
    {
        for(int i=0;i<n;i++)
        {
            if(i==0)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        cout<<endl;
    }
    else
    {
        a[0]=1;
        for(int i=2;i<=n;i++)
        {
           int ok=1;
           a[cur]=i;
         for(int j=1;j<cur;j++)
         {
             if(a[j]==a[cur])
             {
                 ok=0;
                 break;
             }
         }

            if(cur==n-1&&ok)
            {
                if(prime(a[cur]+1)&&prime(a[cur]+a[cur-1]))prime_circle(cur+1);
            }
            else if(ok&&prime(a[cur]+a[cur-1]))
                prime_circle(cur+1);
        }
    }
}
int main()
{
    while(cin>>n)
    {
        tot++;
        printf("Case %d:\n",tot);
        memset(a,0,sizeof(a));
         prime_circle(1);
         cout<<endl;
    }

    return 0;
}
