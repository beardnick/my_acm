#include<stdio.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)&&(a!=0||b!=0))//both of a and b equal 0,then end it ,so you should use ||
    printf("%d\n",a+b);
    return 0;
}
