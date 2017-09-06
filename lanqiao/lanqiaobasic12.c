#include<stdio.h>
#include<ctype.h>
 int a2[404000],a8[2020000];
    char str16[1010000];
void d16tod2(char str[],int a[]);
int d2tod8(int a[],int b[]);
int  main()
{
    int n,i,t;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str16);
      if('0'==str16[0])printf("0\n");
      else
      {
          d16tod2(str16,a2);
      t=d2tod8(a2,a8);
            for(i=t;i>=0;printf("%d",a8[i--]));
            printf("\n");
      }
    }
    return 0;
}
void d16tod2(char str[],int a[])
{
    int i,temp,j;
    for(i=0;str[i]!='\0';i++)
    {

        if(!isdigit(str[i]))temp=str[i]-'A'+10;
        else temp=str[i]-'0';
        for(j=(i+1)*4-1;j>=(i+1)*4-4;j--)
        {
        if(temp){a[j]=temp%2;temp/=2;}
        else if(j>=(i+1)*4-4){a[j]=0;}
        }
    }
    a[j+5]=EOF;
}
int d2tod8(int a[],int b[])
{
    int i,j=1,counter=-1;
    while(a[++counter]!=EOF);
    for(i=0;j;i++)
    {
        j=counter-3*i;
        if(j-3>=0)b[i]=a[--j]+a[--j]*2+a[--j]*4;
        else if(j-3==-1)b[i]=a[--j]+a[--j]*2;
        else if(j-3==-2)b[i]=a[--j];
    }
    i--;
    if(0==b[i])i--;
    return i;
}

