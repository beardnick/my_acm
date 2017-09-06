#include<stdio.h>
int mfab(int x)
{
    if(x>0)return x;
    else return -x;
}
void tran(int n,int r,char str[])
{
    int counter=0,i;
    char ch;
    n=mfab(n);
    while(n)
    {
        if(n%r>=10)str[counter++]=n%r-10+'A';
        else str[counter++]='0'+n%r;
        n/=r;
    }
    str[counter]='\0';
    for(i=0;i<counter/2;i++)
        {
            ch=str[i];
            str[i]=str[counter-1-i];
            str[counter-1-i]=ch;
        }
}
int main()
{
    int n,r;
    char str[1000];
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        tran(n,r,str);
        if(n<0)printf("-");
        puts(str);
    }
    return 0;
}
