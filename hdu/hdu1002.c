#include<stdio.h>
#include<string.h>
#define N 1010
	void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;//�Ӷ���һ���ǿ��ܽ�һλ����һ����'\0'
    c=(char *) malloc(l*sizeof(char));
    i=strlen(a)-1;//�ҵ�a��β��
    j=strlen(b)-1;//�ҵ�b��β��
    k=0;up=0;
    while(i>=0||j>=0)
        {
            if(i<0) x='0'; else x=a[i];//����һ��������һ���ߵ�λ�ļ���
            if(j<0) y='0'; else y=b[j];
            z=x-'0'+y-'0';//������ʹ��ǿ��ת��
            if(up) z+=1;
            if(z>9) {up=1;z%=10;} else up=0;
            c[k++]=z+'0';
            i--;j--;
        }
    if(up) c[k++]='1';//�������Ľ�λ
    i=0;
    c[k]='\0';
    for(k-=1;k>=0;k--)
        back[i++]=c[k];
    back[i]='\0';
}
int main()
{
   int i,n,c=0;
   char str1[N],str2[N],str3[N];
   scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i>1)printf("\n");
       scanf("%s",str1);
       scanf("%s",str2);
        add(str1,str2,str3);
        printf("Case %d:\n",++c);
        //add(str1,str2,str3);
       printf("%s",str1);printf(" + ");printf("%s",str2);printf(" = ");printf("%s",str3);printf("\n");
    }
    return 0;
}
