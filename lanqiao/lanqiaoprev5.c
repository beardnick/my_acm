#include<stdio.h>
#include<ctype.h>
#define N 100010
int counter=-1,counter1=0;
int a[N],b[N];
void cut(int a[],char str[])
{
    int i,sum=0,flag=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(isdigit(str[i]))
        {
            sum*=10;
            sum+=(str[i]-'0');
            flag=1;
        }
        else if(flag)
        {
            a[++counter]=sum;
            sum=0;
            flag=0;
        }
    }
    if(sum!=0)a[++counter]=sum;
    counter1++;
}
int main()
{
    int x,n,m,i,flag=0;
    char ch;
    char str[N];
    scanf("%d",&x);
    getchar();
    while(counter1!=x)
    {
        gets(str);
        cut(a,str);
    }

    for(i=0;i<=counter;i++)
            b[a[i]]++;
    /*
    for(i=0;i<=counter;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=0;!(b[i]>0&&b[i+1]==0&&b[i+2]==0);i++)
        printf("%d ",b[i]);
    printf("\n");
    */
    for(i=0;!(b[i]>0&&b[i+1]==0&&b[i+2]==0);i++)
        {
            if(b[i]==0&&b[i-1]>0&&b[i+1]>0)m=i;
            if(b[i]==2)n=i;
        }
    printf("%d %d\n",m,n);
    return 0;
}
