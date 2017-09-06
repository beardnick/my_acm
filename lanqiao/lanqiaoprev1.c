#include<stdio.h>
int g(int x,int y)
{
    return x/l(x,y)*y;
}
int l(int x,int y)
{
    int i;
    while(x!=y&&x&&y)
    {
        i=x%y;
        x=y;
        y=i;
    }
    return x;
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    b=g(a,b);
    c=g(b,c);
    printf("%d\n",c);
    return 0;
}
