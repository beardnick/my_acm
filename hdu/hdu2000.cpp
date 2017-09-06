#include<stdio.h>
void swap(char *x,char *y);
int main()
{
    char str[3];
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]>str[1])swap(&str[0],&str[1]);
        if(str[0]>str[2])swap(&str[0],&str[2]);
        if(str[1]>str[2])swap(&str[1],&str[2]);
        printf("%c %c %c\n",str[0],str[1],str[2]);
    }
    return 0;
}
void swap(char* x,char* y)
{
    char z;
    z=*x;
    *x=*y;
    *y=z;
}
