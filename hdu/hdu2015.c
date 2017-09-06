#include<stdio.h>
int main()
{
    int a[100],n,m,sum=0,i;
    for(i=0;i<100;i++)
    {
        a[i]=2*(i+1);
    }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
          if(0==(i+1)%m)
          {
              if((i+1)/m==1)
              {
                  printf("%d",(sum+a[i])/m);
                  sum=0;
              }
              else
              {
                  printf(" %d",(sum+a[i])/m);
                  sum=0;
              }
              continue;
          }
          sum+=a[i];
        }
        if(n%m)
        printf(" %d\n",sum/(n%m));
        else printf("\n");
    }
    return 0;
}
