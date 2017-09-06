#include<stdio.h>
int inse(int a[],int n,int m);
int main()
{
    int a[110],n,m,i,k;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        k=inse(a,n,m);
        for(i=0;i<n;i++)
        {
            if(0==k&&0==i)printf("%d",m);
            else if(i==k)printf(" %d",m);
            if(0==i&&k!=0)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        if(n==k)printf(" %d\n",m);
        else printf("\n");
    }
    return 0;
}
int inse(int a[],int n,int m)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(a[0]>=m)return 0;
        else if(a[i]<=m&&m<=a[i+1])
            return i+1;
    }
    return n;
}
