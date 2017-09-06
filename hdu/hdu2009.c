#include<stdio.h>
#include<math.h>
int main()
{
    double m,n,sum;
    while(scanf("%lf%lf",&n,&m)!=EOF)
    {
        sum=0;
        sum+=n;
        while(--m)
            {
                sum+=(n=sqrt(n));
            }
        printf("%.2f\n",sum);
    }
    return 0;
}
