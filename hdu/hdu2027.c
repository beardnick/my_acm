#include<stdio.h>
int main()
{
    char str[110];
    int counta=0,counte=0,counti=0,counto=0,countu=0;
    int i,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str);
        counta=counte=counti=counto=countu=0;
        for(i=0;str[i]!='\0';i++)
        {
            switch(str[i])
            {
                case 'a':counta++;break;
                case 'e':counte++;break;
                case 'i':counti++;break;
                case 'o':counto++;break;
                case 'u':countu++;break;
                default:break;
            }
        }
         printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",counta,counte,counti,counto,countu);
         if(n)printf("\n");
    }
    return 0;
}
