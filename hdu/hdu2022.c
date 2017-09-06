#include<stdio.h>
int mfab(int x)
{
    if(x>0)return x;
    else return -x;
}
int main()
{
    int n,m,counter,i,j,k,a,t,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        counter=0;
        b=1;
        for(k=1;k<=n*m;k++)
        {
            if(1==k)
            {
            counter++;
            scanf("%d",&t);
            }
            else
            {
                 counter++;
                scanf("%d",&a);
            }
            if(mfab(a)>mfab(t)&&k>=2)
            {
                b=counter;
                t=a;
            }
        }
        if(b%m==0)
        {
            j=m;
            i=b/m;
        }
        else
        {
            j=b%m;
            i=b/m+1;
        }
        printf("%d %d %d\n",i,j,t);
    }
    return 0;
}

