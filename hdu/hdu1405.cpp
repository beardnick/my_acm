#include<stdio.h>
int main()
{
   int n,i,counter=0,counter1=1;
    while(scanf("%d",&n)&&n>0)
    {
        if(counter1>1)printf("\n");
        printf("Case %d.\n",counter1++);
        for(i=2;n!=1;i++)
        {
            if(0==n%i)
            {
                counter++;
                n/=i;
                i--;
            }
            else if(counter)
            {
                printf("%d %d ",i,counter);
                counter=0;
            }

        }
        printf("%d %d \n",i,counter);
        counter=0;
    }
    return 0;
}
