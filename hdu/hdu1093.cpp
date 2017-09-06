#include<stdio.h>
int main()
{
    int a,n,sum,m;
    scanf("%d",&m);
    while(m--)
    {
         scanf("%d",&n);
        sum=0;
        while(n--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        if(0==m)printf("%d\n",sum);
        else
        printf("%d\n",sum);
    }
    return 0;
}
