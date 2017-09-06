#include<stdio.h>
#include<string.h>
int ten(int n);
#define M 90
#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01
int main()
{
    char str[M];
    int n,sum=0,counter=-1,i,flag=0;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str);
        int rec[4]={0};
      //  puts(str);
      for(i=strlen(str)-1;i>=0;i--)
      {
          if(str[i]-'0'>=0&&str[i]-'0'<=9)
          {
              if(!flag)
              {
                  sum=0;
                  counter=-1;
              }
              sum+=ten(++counter)*(str[i]-'0');
              flag=1;
          }
            else
            {
                if(flag)
                {
                    switch(str[i])
                    {
                        case 'C':rec[0]+=sum;break;
                        case 'H':rec[1]+=sum;break;
                        case 'O':rec[2]+=sum;break;
                        case 'N':rec[3]+=sum;break;
                    }
                }
                else
                {
                    switch(str[i])
                    {
                        case 'C':rec[0]++;break;
                        case 'H':rec[1]++;break;
                        case 'O':rec[2]++;break;
                        case 'N':rec[3]++;break;
                    }
                }
                flag=0;
                }
            }
            /*
            for(int j=0;j<4;j++)
                printf("%d ",rec[j]);
                */
            printf("%.3f\n",rec[0]*C+rec[1]*H+rec[2]*O+rec[3]*N);
      }

    return 0;
}
int ten(int n)
{
    int sum=1;
    for(int i=0;i<n;i++)
        sum*=10;
    return sum;
}
//下次分成函数写
