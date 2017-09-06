#include<stdio.h>
int main()
{
    int a,b,c;
    int n;
    double m;
    while(scanf("%d",&n)&&n)
    {
        a=b=c=0;
        while(n--)
        {
            scanf("%lf",&m);
            if(m>0)a++;
    else if(m==0)b++;
    else if(m<0)c++;

        }
        printf("%d %d %d\n",c,b,a);
    }
    return 0;
}
