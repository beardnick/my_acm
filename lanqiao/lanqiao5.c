#include<stdio.h>
#define N 100000000
long conversion(char s[],char s2[],long d1,long d2)
{
    long i,j,t,num;
    char c;
    num=0;
    for (i=0;s[i]!='\0';i++)
        {
        if (s[i]<='9'&&s[i]>='0') t=s[i]-'0'; else t=s[i]-'A'+10;
        num=num*d1+t;
        }
        //printf("%d %d\n",num,1);
    i=0;
    while(1)
        {
        t=num%d2;
        if (t<=9) s2[i]=t+'0'; else s2[i]=t+'A'-10;
        num/=d2;
        if (num==0) break;
        i++;
        }
      for(j=i;j>=0;j--)
            printf("%c",s2[j]);
        printf("\n");
/*
    for (j=0;j<=i/2;j++)
        {c=s2[j];
        s2[j]=s[i-j];
        s2[i-j]=c;
      }
    s2[i+1]='\0';
    puts(s2);
*/
return i;
}
char str1[N],str2[N];
int main()
{
    long a=16,b=8;
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str1);
        conversion(str1,str2,a,b);
    }
    return 0;
}
