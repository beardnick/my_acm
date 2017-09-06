#include<stdio.h>
int main()
{
    int a[110],m,i=0,j;
    double sum;
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        {
            sum=0;
            for(j=1;j<=a[i];j++)
            {
                if(0==j%2)sum-=1.0/j;
                else sum+=1.0/j;
            }
            printf("%.2f\n",sum);
        }
    }
    return 0;
}
