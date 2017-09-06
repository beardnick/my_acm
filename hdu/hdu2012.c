#include<stdio.h>
int main()
{
    int x,y,i,temp,flag,j;
    while(scanf("%d%d",&x,&y)&&(x||y))
    {
        flag=1;
        for(i=x;i<=y;i++)
        {
            temp=i*i+i+41;
            for(j=2;j<temp;j++)
                if(0==temp%j)
            {
                flag=0;
                break;
            }
            if(!flag)break;
        }
        if(flag)printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}
