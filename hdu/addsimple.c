 #include<stdio.h>
 #include<string.h>
 	void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;//�Ӷ���һ���ǿ��ܽ�һλ����һ����'\0'
    c=(char *) malloc(l*sizeof(char));
    k=0;up=0;
    for(i=strlen(a)-1,j=strlen(b)-1;i>=0||j>=0;i--,j--)
        {
            if(i<0) x='0'; else x=a[i];//����һ��������һ���ߵ�λ�ļ���
            if(j<0) y='0'; else y=b[j];
            z=x-'0'+y-'0';//������ʹ��ǿ��ת��
            if(up) ++z;
            if(z>9) {up=1;z%=10;} else up=0;
            c[k++]=z+'0';
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
    char str1[100],str2[100],str3[100];
    gets(str1);
    gets(str2);
    add(str1,str2,str3);
    puts(str3);
}
