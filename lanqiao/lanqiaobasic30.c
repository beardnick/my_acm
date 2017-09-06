#include<stdio.h>
#define N 10000
#define M 10000
int a[N]={10000};
void f(int n,int a[]);
void output(int a[]);
int main()
{
    int n;
    scanf("%d",&n);
    f(n,a);
    output(a);
    return 0;
}
void f(int n,int a[])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=N;j>=0;j--)if(a[j])a[j]*=i;
        for(j=0;j<N;j++)
            if(a[j]>=M){a[j+1]+=(a[j]/M);a[j]%=M;}
    }
}
void output(int a[])
{
    int counter=N;
    while(a[--counter]==0);
    counter++;
    while(counter--)printf("%d",a[counter]);
    printf("\n");
}
