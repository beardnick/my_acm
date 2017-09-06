#include<stdio.h>
int main()
{
    int a,b,c,i,m,n,flag=0;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        flag=0;
        for(i=m;i<=n;i++)
        {
            a=i/100;
            b=i%100/10;
            c=i%10;
            if(a*a*a+b*b*b+c*c*c==i)
            {
                if(0==flag)printf("%d",i);
                 else printf(" %d",i);
                 flag=1;
            }
        }
        if(0==flag)printf("no\n");
        else printf("\n");
    }
    return 0;
}
