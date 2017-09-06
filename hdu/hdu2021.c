#include<stdio.h>
int calc(int a[],int n);
int main()
{
    int n,a[110],i;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",calc(a,n));
    }
    return 0;
}
int calc(int a[],int n)
{
    int i,counter=0,sum=0;
    for(i=0;i<n;i++)
    {
        while(a[i])
        {
            if(a[i]/100){counter++;a[i]-=100;}
    else if(a[i]/50){counter++;a[i]-=50;}
    else if(a[i]/10){counter++;a[i]-=10;}
    else if(a[i]/5){counter++;a[i]-=5;}
    else if(a[i]/2){counter++;a[i]-=2;}
    else if(a[i]){counter++;a[i]-=1;}
        }
         sum+=counter;
        counter=0;
    }
    return sum;
}
