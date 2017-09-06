#include<stdio.h>
#define N 6
void add(int a[]);
int main()
{
    int a[N]={0,1,0,0,0,0};
    int n;
    scanf("%d",&n);
    while(a[5]!=9||a[1]!=9||a[2]!=9||a[3]!=9||a[4]!=9)
    {
        add(a);
/*
         for(int i=1;i<6;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
*/
        if(a[5]+a[1]+a[2]+a[3]+a[4]==n&&a[5]==a[1]&&a[4]==a[2])
        {
            for(int i=1;i<6;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
    while(a[5]!=9||a[1]!=9||a[2]!=9||a[3]!=9||a[4]!=9||a[0]!=9)
    {
        add(a);
        if(a[5]+a[1]+a[2]+a[3]+a[4]+a[0]==n&&a[5]==a[0]&&a[4]==a[1]&&a[3]==a[2])
        {
            for(int i=0;i<6;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
void add(int a[])
{
    int i;
    a[N-1]+=1;
    for(i=N-1;i>0;i--)
    {
        if(a[i]>=10)
        {
            a[i-1]+=1;
            a[i]=(a[i]%10);
        }
    }
}
