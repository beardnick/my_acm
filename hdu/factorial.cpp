 #include<stdio.h>
 #include<math.h>
 //阶乘运算
int factorial(int n)
{
long a[10000];
int i,j,l,c,m=0,w;
a[0]=1;
for(i=1;i<=n;i++)//外层循环要计算阶乘
{
    c=0;
    for(j=0;j<=m;j++)//内层循环要控制进位
    {
        a[j]=a[j]*i+c;//当前位乘以阶乘计算算到的数再加上进位的c
        c=a[j]/10000;//计算出进往高位进的数
        a[j]=a[j]%10000;//计算出当前位余下的数
    }
    if(c>0) {m++;a[m]=c;}
}
printf("%d!=",n);
printf("%ld",a[m]); //格式控制，不可以删去
w=m*4+log10(a[m])+1;//计算数据的位数
for(i=m-1;i>=0;i--) printf("%4.4ld",a[i]);
printf("%10d",w);
printf("\n");
return w;
}
int main()
{
    int n,i;
    scanf("%d",&n);
  for(i=1;i<=n;i++)
      factorial(i);
      return 0;
}
