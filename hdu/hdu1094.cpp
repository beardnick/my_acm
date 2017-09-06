#include<stdio.h>
int main()
{
    int a,n,sum,m;
   while(scanf("%d",&n)!=EOF)
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
