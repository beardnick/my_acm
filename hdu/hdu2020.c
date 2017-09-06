#include<stdio.h>
#include<math.h>
#define N 110
void sort(int a[],int n);
int main()
{
    int a[N];
    int n,i;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      //for(i=0;i<n;i++)
       // printf("%d ",a[i]);
      sort(a,n);
    }
    return 0;
}
void sort(int a[],int n)
{
    int j,i,k;
    for(i=0;i<n-1;i++)
    {
             k=i;
        for(j=i+1;j<n;j++)
        {
            if(fabs(a[j])>fabs(a[k]))k=j;
        }
        if(i!=k)
        a[i]^=a[k]^=a[i]^=a[k];
    }
    for(i=0;i<n;i++)
    {
        if(0==i)printf("%d",a[i]);
        else printf(" %d",a[i]);
    }
    printf("\n");
}
