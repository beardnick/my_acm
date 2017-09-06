#include<stdio.h>
void find(int a[],int n);
int main()
{
    int a[110],n,i;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        find(a,n);
        for(i=0;i<n;i++)
        {
            if(0==i)printf("%d",a[i]);
            else printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
void find(int a[],int n)
{
    int i,k=0,t;
    for(i=1;i<n;i++)
    {
        if(a[i]<a[k])k=i;
    }
  {
      t=a[k];
        a[k]=a[0];
      a[0]=t;
   }
}
