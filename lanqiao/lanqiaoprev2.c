#include<stdio.h>
#define N 1000
char a[N][N];
void add(char a[N][N])
{
    int i,j;
    int counter=0;
    for(i=1;i<N-1;i++)
        for(j=1;j<N-1;j++)
            if(a[i][j]=='$')
            {
                if(a[i-1][j]==0)a[i-1][j]='.';
                if(a[i+1][j]==0)a[i+1][j]='.';
                if(a[i][j-1]==0)a[i][j-1]='.';
                if(a[i][j+1]==0)a[i][j+1]='.';
                if(a[i-1][j-1]==0)a[i-1][j-1]='.';
                if(a[i+1][j-1]==0)a[i+1][j-1]='.';
                if(a[i-1][j+1]==0)a[i-1][j+1]='.';
                if(a[i+1][j+1]==0)a[i+1][j+1]='.';
            }
    for(i=1;i<N-1;i++)
        for(j=1;j<N-1;j++)
            if(a[i][j]=='.')
            {
                if(a[i-1][j]==0)a[i-1][j]='$';
                if(a[i+1][j]==0)a[i+1][j]='$';
                if(a[i][j-1]==0)a[i][j-1]='$';
                if(a[i][j+1]==0)a[i][j+1]='$';
                if(a[i-1][j-1]==0)a[i-1][j-1]='$';
                if(a[i+1][j-1]==0)a[i+1][j-1]='$';
                if(a[i-1][j+1]==0)a[i-1][j+1]='$';
                if(a[i+1][j+1]==0)a[i+1][j+1]='$';
            }
}
void add1(char a[N][N],int n)
{
    int t=2*n+2;
    int i,j;
    i=j=N/2;
    a[i+t][j+t]=a[i+t-1][j+t]=a[i+t][j+t-1]=a[i+t-1][j+t-1]='.';
    a[i+t][j-t]=a[i+t][j-t+1]=a[i+t-1][j-t]=a[i+t-1][j-t+1]='.';
    a[i-t][j+t]=a[i-t+1][j+t]=a[i-t][j+t-1]=a[i-t+1][j+t-1]='.';
    a[i-t][j-t]=a[i-t+1][j-t]=a[i-t][j-t+1]=a[i-t+1][j-t+1]='.';
}
void output()

{
    int i,j,flag=0;
    for(i=1;i<N-1;i++)
    {
        flag=0;
        for(j=1;j<N-1;j++)
        {
            if(a[i][j]!=0){printf("%c",a[i][j]);flag++;}
        }
        if(flag)printf("\n");
    }

}
/*
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
}
*/
int main()
{
    a[N/2][N/2]=a[N/2-1][N/2]=a[N/2-2][N/2]=a[N/2+1][N/2]=a[N/2+2][N/2]=a[N/2][N/2-1]=a[N/2][N/2-2]=a[N/2][N/2+1]=a[N/2][N/2+2]='$';
    int n,i;
    scanf("%d",&n);
   for(i=0;i<n;i++)add(a);
   add1(a,n);
    output(a);
    return 0;
}
