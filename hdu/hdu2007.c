#include<stdio.h>
int main()
{
    int m,n,sum2,sum3,i;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m>n)m^=n^=m^=n;
        sum2=0;
        sum3=0;
        for(i=m;i<=n;i++)
        {
            if(0==i%2)sum2+=(i*i);
            else sum3+=(i*i*i);
        }
        printf("%d %d\n",sum2,sum3);
    }
    return 0;
}
