#include<stdio.h>
int main()
{
    int n,counter;
    char ch;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        counter=0;
        while((ch=getchar())!='\n')
        {
            if(ch<0)counter++;
        }
        printf("%d\n",counter/2);
    }
    return 0;
}
