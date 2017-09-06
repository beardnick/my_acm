#include<stdio.h>
int main()
{
    char ch;
    int counter=0,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        counter=0;
        while((ch=getchar())!='\n')
        if(ch-'0'>=0&&ch-'0'<=9)counter++;
        printf("%d\n",counter);
    }
    return 0;
}
