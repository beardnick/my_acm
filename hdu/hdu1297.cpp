#include<stdio.h>
int f(int n);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",f(n));
    }
    return 0;
}
int f(int n)
{
    if(1==n||2==n)return n;
    if(3==n)return 4;
    else return 2*(f(n-1)-1)+1;
}
