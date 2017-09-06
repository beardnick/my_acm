#include <stdio.h>
#include <stdlib.h>
int main()
{
    int s=1,h;
    int i, j;
    while(scanf("%d",&h)!=EOF)
    {printf("1\n");
    for (i=2;i<=h;s=1,i++)
    {
        printf("1 ");
        for (j=1;j<=i-2;j++)
            printf("%d ",(s=(i-j)*s/j));
        printf("1\n");
    }
    printf("\n");
    }
    return 0;
}

