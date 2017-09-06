#include<stdio.h>
int main()
{
    int n,sum,counter;
    char ch;
    scanf("%d",&n);
    while(n--)
    {
        counter=0;
        sum=0;
     //  getchar();
        while(ch=getchar()!='\n')
        {
            if('X'==ch)
            {
                sum+=counter;
                counter=0;
                }
            else if('O'==ch)counter++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
