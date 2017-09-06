#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[120],b[120],c[200];
void  calc(char a[],char b[]);
int main()
{
    gets(a);
    gets(b);
    calc(a,b);
    return 0;
}
void  calc(char a[],char b[])
{
    int n,i,j,temp,counter=-1,al,bl;
    char ch;
    al=strlen(a);
    bl=strlen(b);
    for(i=al-1,j=bl-1;i>=0||j>=0;i--,j--)
    {
        temp=0;
        if(i>=0)temp+=a[i]-'0';
        if(j>=0)temp+=b[j]-'0';
        c[++counter]=temp+'0';
    }
    for(i=0;c[i]!='\0';i++)
    {
        if(!isdigit(c[i]))
        {
            temp=c[i]-'0';
            c[i+1]+=(temp/10);
            c[i]=temp%10+'0';
        }
    }
    for(j=0;j<i/2;j++)
        {
            ch=c[j];
            c[j]=c[i-1-j];
            c[i-1-j]=ch;
        }
        puts(c);
}
