#include<stdio.h>
void calc(double a[60][10],int n,int m);
int counter(double a[60][10],int n,int m);
int main()
{
    double a[60][10];
    int m,n,i,j;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%lf",&a[i][j]);
        calc(a,n,m);
        for(i=0;i<n;i++)
        {
            if(0==i)printf("%.2f",a[i][m+1]);
            else printf(" %.2f",a[i][m+1]);
        }
        printf("\n");
          for(j=0;j<m;j++)
        {
            if(0==j)printf("%.2f",a[n+1][j]);
            else printf(" %.2f",a[n+1][j]);
        }
        printf("\n");
        printf("%d\n\n",counter(a,n,m));
    }
    return 0;
}
void calc(double a[60][10],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        a[i][m+1]=0;
        for(j=0;j<m;j++)
        {
            a[i][m+1]+=a[i][j];
        }
        a[i][m+1]/=m;
    }
    for(j=0;j<m;j++)
    {
        a[n+1][j]=0;
        for(i=0;i<n;i++)
        {
            a[n+1][j]+=a[i][j];
        }
        a[n+1][j]/=n;
    }
}
int counter(double a[60][10],int n,int m)
{
    int i,j,flag,counter1=0;
    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=0;j<m;j++)
        {
            if(a[i][j]<a[n+1][j])
            {
                flag=0;
                break;
            }
        }
        if(flag)counter1++;
    }
 return counter1;
}
