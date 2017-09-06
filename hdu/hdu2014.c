#include<stdio.h>
void find(int a[],int n);
int main()
{
    int a[110],n,i;
    double sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        find(a,n);
        for(i=0;i<n;i++)
            sum+=a[i];
        printf("%.2f\n",sum/(n-2));
    }
    return 0;
}
void find(int a[],int n)
{
    int i,maxn,minn;
    maxn=minn=0;
    for(i=1;i<n;i++)
    {
        if(a[i]>a[maxn])maxn=i;
        if(a[i]<a[minn])minn=i;
    }
    a[maxn]=a[minn]=0;
}
