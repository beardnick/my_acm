#include<stdio.h>
int main()
{
    const double PI=3.1415927;
    double r;
    while(scanf("%lf",&r)!=EOF)
    {
        printf("%.3f\n",4.0/3*PI*r*r*r);
    }
    return 0;
}
