#include<stdio.h>
int main()
{
    char str[100];
    int a,i,j;
    scanf("%d",&a);
    if(0==a)printf("0\n");
    else
    {
        for(i=0;a;i++)
    {
        if(a%16>=10)str[i]=a%16-10+'A';
        else str[i]=a%16+'0';
        a/=16;
    }
    for(j=i;j;)
    {
        printf("%c",str[--j]);
    }
    printf("\n");
    }

    return 0;
}
