#include<stdio.h>
long long p(int n)
{
    long long sum=1;
    int i;
    for(i=1;i<=n;i++)
        sum*=3;
    return sum;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",p(n));
    }
    return 0;
}
