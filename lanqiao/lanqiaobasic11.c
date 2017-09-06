#include<stdio.h>
#include<ctype.h>
int main()
{
    char str[20];
    long long sum=0,i,temp;
   gets(str);

        sum=0;
        for(i=0;str[i]!='\0';i++)
        {
            if(isalpha(str[i]))temp=str[i]-'A'+10;
            else temp=str[i]-'0';
            sum+=temp;
            sum*=16;
        }
        printf("%lld\n",sum/=16);

    return 0;
}
