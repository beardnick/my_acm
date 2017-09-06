#include<stdio.h>
int main()
{
    int sco;
    while(scanf("%d",&sco)!=EOF)
    {
        if(sco>=90&&sco<=100)printf("A\n");
else if(sco>=80&&sco<=89)printf("B\n");
else if(sco>=70&&sco<=79)printf("C\n");
else if(sco>=60&&sco<=69)printf("D\n");
else if(sco>=0&&sco<=59)printf("E\n");
else printf("Score is error!\n");
    }
    return 0;
}
