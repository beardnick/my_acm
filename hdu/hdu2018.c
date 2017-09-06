#include<stdio.h>
void f(int n,int a[]);
int main()
{
    int n,a[60];
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=4;
    while(scanf("%d",&n)&&n)
    {
        f(n,a);
        printf("%d\n",a[n]);
    }
    return 0;
}
void f(int n,int a[])
{
    int i;
    for(i=5;i<=n;i++)
        a[i]=a[i-1]+a[i-3];
}
