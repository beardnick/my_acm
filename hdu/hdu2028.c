#include<stdio.h>
int low(int x,int y);
int gre(int x,int y);int low(int x,int y);
int gre(int x,int y);
int main()
{
    int n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&a);
        while(--n)
        {
            scanf("%d",&b);
            a=low(a,b);
        }
        printf("%d\n",a);
    }
    return 0;
}
int low(int x,int y)
{
    return (x/gre(x,y))*y;
}
int gre(int x,int y)
{
    int i;
    while(x!=y&&y!=0)
    {
        i=x%y;
        x=y;
        y=i;
    }
    return x;
}
