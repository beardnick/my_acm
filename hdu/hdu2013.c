#include<stdio.h>
int main()
{
    int a=1,n;
    while(scanf("%d",&n)!=EOF)
    {
        a=1;
        while(--n)
            a=(a+1)*2;
        printf("%d\n",a);
    }
    return 0;
}
