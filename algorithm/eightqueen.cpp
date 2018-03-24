#include<stdio.h>
#include<stdlib.h>
#define Queens 8
int a[Queens+1]; //八皇后问题的皇后所在每一行位置，从1开始算
int main()
{
int i,k,flag,not_finish=1,count=0;
i=1;//初始
a[1]=1;
printf("the possible configuration of 8 queesns are:\n");
while(not_finish) //not_finsh=1:处理未结束
{
while(not_finish && i<Queens+1) //处理未结束
{
for(flag=1,k=1;flag && k<i;k++)//判断是否有多个皇后在同一行
if(a[k]==a[i])
flag=0;
for(k=1;flag && k<i;k++) //判断是否有多个皇后在对角线
if((a[i]==a[k]-(k-i))||(a[i]==a[k]+(k-i)))
flag=0;
if(!flag) //若存在矛盾 重设第i个元素
{
if(a[i]==a[i-1]) //若a[i]的值已经已经一圈追上a[i-1]的值
{
i--; //退回一步 重新试探处理前一个元素
if(i>1 && a[i]==Queens)
a[i]=1; // 当a[i]为 Queens时 将a[i]的值重置
else
if(i==1 && a[i]==Queens)//当第一未位的值达到Queens时结束
not_finish=0;
else
a[i]++;
}
else
if(a[i]==Queens)
a[i]=1;
else
a[i]++;
}
else
if(++i<=Queens) //若前一个元素的值为Queens
if(a[i-1]==Queens)
a[i]=1;
else //否则元素为前一个元素的下一个值
a[i]=a[i-1]+1;
}
if (not_finish)
{
++count;
printf((count-1)%3?"[%2d]:":"\n[%2d]:",count);
for(k=1;k<=Queens;k++) //输出结果
printf("%d",a[k]);
if(a[Queens-1]<Queens)
a[Queens-1]++;
else
a[Queens-1]=1;
i=Queens-1;
}
}
system("pause");
}
