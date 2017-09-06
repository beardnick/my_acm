#include<stdio.h>
#include<math.h>
#define N 3
int narc(int a[]);
void add(int a[]);
int main()
{
    int a[N]={1,0,0};
    for(;;)
    {
    add(a);
/*
          for(int i=0;i<N;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");

 /*       if(pow(a[0],3)+pow(a[1],3)+pow(a[2],3)==a[0]*100+a[1]*10+a[2])
           {
              for(int i=0;i<N;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }

    if(narc(a))
    {
         for(int i=0;i<N;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
    }
*/
narc(a);
        if(a[0]+a[1]+a[2]==27)break;
    }
    return 0;
}
void add(int a[])
{
    int i;
    a[N-1]+=1;
    for(i=N-1;i>0;i--)
    {
        if(a[i]>=10)
        {
            a[i-1]+=1;
            a[i]=(a[i]%10);
        }
    }
}
int narc(int a[])
{
	int i,sum=0,self=0;
for(i=0;i<N;i++)
	{
		sum+=pow(a[i],3);
		self+=(int)(pow(10,(N-i-1)))*a[i];//double pow(double x,double y)在计算时有误差，如它把10的平方算成了99
		printf("%d\n",self);
	}
	  printf("%d,%d\n",sum,self);
    if(self==sum)return 1;
    else return 0;
}
