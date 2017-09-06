#include<stdio.h>
int p(int a)
{
    int i,sum=1;
    for(i=1;i<=a;i++)
        sum*=2;
    return sum;
}
int f(int n)
{
    int i;
    if(1==n)return 1;
    else
    {
        for(i=2;!((i-1)*i/2<n&&n<=(i+1)*i/2);i++);
        i--;
        return f(n-1)+p(i);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",f(n));
    return 0;
}
