/*
 * n queens problem
 * there are n queens
 * and a n X n chessboard
 * */
#include <stdio.h>

int tot,C[100],n;    //C[i] is the position of the queen in i rows
void search(int cur)

{
    if(cur==n)
    {
        tot++;
        int i;
        int j;
        printf("number %d\n\n", tot);
        for( i = 0 ; i < n ; i ++){
            for( j = 0 ; j < n; j ++ ){
                if( j + 1== C[i] + 1)printf("0 ");
                else printf("1 ");
            }
            printf("\n");
        }
        printf("\n\n");
    }
    else for(int i=0;i<n;i++)//��ѭ�����ٶ�һ�����лʺ��λ��
        {
            int ok=1;
            C[cur]=i;
            for(int j=0;j<cur;j++)//��ѭ��������Ƿ���j�е�ì�ܣ�����ì��������һ���ߣ�ì����ı䱾�лʺ�λ��
                if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j])
                {
                    ok=0;break;
                }
            if(ok)search(cur+1);
        }//���ȫ��ì�ܣ�����·�Ͳ�������������ˣ�������������Ӱ��tot��ֵ
}
int main()
{
    tot=0;
    scanf("%d",&n);
    search(0);
    printf("there are %d keys for %d queens problem\n", tot , n);
    return 0;
}
