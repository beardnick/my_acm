#include<stdio.h>
#include<string.h>
#define N 110
int find(char str[],int n);
void put(char str[],int n,int k);
int main()
{
    char str[N];
    int k,n;
    while(scanf("%s",str)!=EOF)
    {
        n=strlen(str);
       // printf("%d",n);//"abc",3==n
    k=find(str,n);
    put(str,n,k);
    }

    return 0;
}
int find(char str[],int n)
{
    int i,k=0;
    for(i=1;i<n;i++)
    {
       if(str[i]>str[k])k=i;
    }
    return k;
}
void put(char str[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(str[i]==str[k])
        {
            printf("%c(max)",str[i]);
        }
        else printf("%c",str[i]);
    }
    printf("\n");
}
