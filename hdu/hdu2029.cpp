#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    int n,i,m,flag=1;
    scanf("%d",&n);
    while(n--)
    {
        flag=1;
        scanf("%s",str);
        m=strlen(str);
        for(i=0;i<m/2;i++)
        {
            if(str[i]!=str[m-1-i])
            {
                flag=0;
                break;
            }
        }
        if(flag)printf("yes\n");
        else printf("no\n");
    }
}
