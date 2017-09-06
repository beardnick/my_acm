#include<stdio.h>
int main()
{
    int a,n,sum;
    while(scanf("%d",&n)&&n)
    {
        sum=0;
        while(n--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
    }
    return 0;
}
