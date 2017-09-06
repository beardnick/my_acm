#include<stdio.h>
long long p(int n)
{
    long long sum=1;
    int i;
    for(i=1;i<=n;i++)
        sum*=2;
    return sum;
}
int main()
{
    int n,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%lld\n",p(n-k));
    }
    return 0;
}
