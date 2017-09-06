#include<stdio.h>
int main()
{
    int a[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                             {31,29,31,30,31,30,31,31,30,31,30,31}};
    int leap,year,month,day,i,sum;
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
    {
        sum=0;
      leap=(0==year%4&&year%100!=0) ||year%400==0;
      for(i=0;i<month-1;i++)
      {
          sum+=a[leap][i];
      }
      sum+=day;
      printf("%d\n",sum);
    }
    return 0;
}
