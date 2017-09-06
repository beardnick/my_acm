#include<stdio.h>
#include<ctype.h>
int main()
{
    char str[200];
    int i;
    while(gets(str))
    {
        if(str[0]>'Z')str[0]-=32;
        for(i=1;str[i]!='\0';i++)
        {
            if(!isalpha(str[i-1])&&islower(str[i]))str[i]-=32;
        }
        printf("%s\n",str);
    }
    return 0;
}
