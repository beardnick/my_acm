 #include<stdio.h>
 #include<math.h>
 //�׳�����
int factorial(int n)
{
long a[10000];
int i,j,l,c,m=0,w;
a[0]=1;
for(i=1;i<=n;i++)//���ѭ��Ҫ����׳�
{
    c=0;
    for(j=0;j<=m;j++)//�ڲ�ѭ��Ҫ���ƽ�λ
    {
        a[j]=a[j]*i+c;//��ǰλ���Խ׳˼����㵽�����ټ��Ͻ�λ��c
        c=a[j]/10000;//�����������λ������
        a[j]=a[j]%10000;//�������ǰλ���µ���
    }
    if(c>0) {m++;a[m]=c;}
}
printf("%d!=",n);
printf("%ld",a[m]); //��ʽ���ƣ�������ɾȥ
w=m*4+log10(a[m])+1;//�������ݵ�λ��
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
