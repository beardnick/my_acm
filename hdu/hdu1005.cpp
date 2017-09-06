#include<stdio.h>
#include<stdio.h>
#define N 7
int f[1000];
void calc(long long n,int  a,int  b,int *loop,int *start);
int main()
{
    f[1]=f[2]=1;
    long long n;
    int a,b;
    while(scanf("%d%d%lld",&a,&b,&n)&&(a!=0&&b!=0&&n!=0))
    {
        int loop=0,start=1;
        calc(n,a,b,&loop,&start);
        printf("loop=%d,start=%d\n",loop,start);
        //printf("3");
        if(n<=start)
            printf("%d\n",f[n]);
        else
        {
            if((n%loop)==0)printf("%d\n",f[start+loop-1]);
            else  printf("%d\n",f[(n-start+1)%loop+start-1]);
        }
    }
    return 0;
}
void calc(long long n,int  a,int b,int *loop,int *start)
{
   for(int i=3;*loop==0;i++)
   {
        f[i]=(a*f[i-1]+b*f[i-2])%N;
        printf("f[%d]=%d\n",i,f[i]);
      for(int j=1;j<i;j++)
      {
          if(f[j]==f[i-1]&&f[j+1]==f[i])
          {
             //printf("1");
              *loop=i-1-j;
              *start=j;
             //printf("2");
              break;
            }
      }
   }
}
//题目本身有一些问题
