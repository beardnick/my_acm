#include<stdio.h>
#define N 4
void add(int a[]);
int main()
{
    int a[N]={1,0,0,0};
    for(;;)
    {
        add(a);
        if(a[0]==a[3]&&a[1]==a[2])
        {
              for(int i=0;i<N;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }
       if(a[0]+a[1]+a[2]+a[3]==36)break;
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
