#include<stdio.h>
#define N 40
void put(int a[]);
void calc(int p[],int n[]);
int main()
{
   // int a[N]={1},b[N]={1};
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        int  a[N]={1},b[N]={1};
        for(j=1;j<=n;j++)
    {
        if(1>=j)printf("1\n");
       else if(0==j%2)
        {
            calc(a,b);
            put(b);
        }
            else
        {
            calc(b,a);
            put(a);
        }

    }
    printf("\n");
    }
    return 0;
}
void put(int a[])
{
    int i;
    for(i=0;a[i]!=0;i++)
    {
        if(0==i)printf("%d",a[i]);
        else  printf(" %d",a[i]);//注意最后不能有空格
    }
    printf("\n");
}
void calc(int p[],int n[])
{
    int i;
    for(i=0;p[i]!=0;i++)
    {
        n[i+1]=p[i]+p[i+1];
    }
}

