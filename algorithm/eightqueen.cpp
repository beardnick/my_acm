#include<stdio.h>
#include<stdlib.h>
#define Queens 8
int a[Queens+1]; //�˻ʺ�����Ļʺ�����ÿһ��λ�ã���1��ʼ��
int main()
{
int i,k,flag,not_finish=1,count=0;
i=1;//��ʼ
a[1]=1;
printf("the possible configuration of 8 queesns are:\n");
while(not_finish) //not_finsh=1:����δ����
{
while(not_finish && i<Queens+1) //����δ����
{
for(flag=1,k=1;flag && k<i;k++)//�ж��Ƿ��ж���ʺ���ͬһ��
if(a[k]==a[i])
flag=0;
for(k=1;flag && k<i;k++) //�ж��Ƿ��ж���ʺ��ڶԽ���
if((a[i]==a[k]-(k-i))||(a[i]==a[k]+(k-i)))
flag=0;
if(!flag) //������ì�� �����i��Ԫ��
{
if(a[i]==a[i-1]) //��a[i]��ֵ�Ѿ��Ѿ�һȦ׷��a[i-1]��ֵ
{
i--; //�˻�һ�� ������̽����ǰһ��Ԫ��
if(i>1 && a[i]==Queens)
a[i]=1; // ��a[i]Ϊ Queensʱ ��a[i]��ֵ����
else
if(i==1 && a[i]==Queens)//����һδλ��ֵ�ﵽQueensʱ����
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
if(++i<=Queens) //��ǰһ��Ԫ�ص�ֵΪQueens
if(a[i-1]==Queens)
a[i]=1;
else //����Ԫ��Ϊǰһ��Ԫ�ص���һ��ֵ
a[i]=a[i-1]+1;
}
if (not_finish)
{
++count;
printf((count-1)%3?"[%2d]:":"\n[%2d]:",count);
for(k=1;k<=Queens;k++) //������
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
