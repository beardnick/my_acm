#include<stdio.h>
int chec(char c[]);
int main()
{
    char ch,c[60];
    int n,flag,i;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(c);
        flag=chec(c);
      if(flag)printf("yes\n");
      else printf("no\n");
    }
    return 0;
}
int chec(char c[])
{
    int i,flag=1,ch;
    ch=c[0];
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_')
    {
        for(i=0;c[i]!='\0';i++)
       {
           ch=c[i];
        if(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_'||(ch>='0'&&ch<='9')))
            {
                flag=0;
                break;
            }
        }
        if(flag)return 1;
        else return 0;
    }
    else return 0;
}
