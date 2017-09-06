#include<stdio.h>
#define N 1010
int change(char str[2][N])
{
    int i,counter=0;
    for(i=0;str[0][i]!='\0';i++)
    {
        if(str[0][i]!=str[1][i])
        {
            if(str[0][i]=='*')str[0][i]='o';
            else str[0][i]='*';
            if(str[0][i+1]=='*')str[0][i+1]='o';
            else str[0][i+1]='*';
            counter++;
        }
    }
    puts(str[0]);
    puts(str[1]);
    return counter;
}
int main()
{
    char str[2][N];
    gets(str[0]);
    gets(str[1]);
    printf("%d\n",change(str));
    return 0;
}
