#include<stdio.h>
#include<math.h>
#define N 10
#define M 20
int trans10(char *str16);
//void trans8();
int main()
{
    int n,res,i;
    char *p16,*p8;
    scanf("%d",&n);
    getchar();
    char str16[N][M],str8[N][M]={'\0'};
    p16=str16;
    p8=str8;
    for( i=0;i<n;i++)
    {
          gets(str16[i]);
          puts(str16[i]);
          res=trans10(p16+M*i);
          printf("%d\n",res);
         // trans8();
    }
    for(i=0;i<n;i++)
        puts(str8[i]);
    return 0;
}
int trans10(char *str16)
{
    int sum=0,c=-1,i;
    for(i=M-1;i>=0;i--)
    {
        printf("%d\n",c);
        printf("%d\n",i);

        while(str16[i]!='\0')
        {
            sum+=(int)str16[i]*pow(16,++c);
            printf("%d\n",c);//why it is a dead loop?
        }
    }
    return sum;
}
//void trans8()
