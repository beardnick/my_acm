#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double n=0,temp=1;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    for(int i=0;i<=9;i++)
    {
        if(i>0)temp*=i;
        n+=(1/temp);
        if(i>=3)
        printf("%d %.9f\n",i,n);
    }
    return 0;
}
