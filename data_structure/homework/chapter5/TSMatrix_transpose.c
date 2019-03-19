#include <stdio.h>
#include "../Matrix/TSMatrix.h"

int main(){
    int a[N][N] = {0};
    int row , col;
    printf("please enter the row number and the col number\n");
    while (!(scanf("%d%d" , &row , &col) && row && col)){
        printf("invalid number , please enter again !\n");
    }

    int i , j;

    for(i = 0 ; i < row ; i ++){
        for(j = 0 ; j < col ; j ++){
            scanf("%d",&a[i][j]);
        }
    }
    TSMatrix matrix;
    Init(&matrix);
    build(&matrix , a , row , col);
    for( i = 1 ; i <= matrix.len ; i ++){
        printf("%d %d %d\n" , matrix.data[i].row , matrix.data[i].col , matrix.data[i].elem);
    }
    TSMatrix matrix1;
    Init(&matrix1);
    Transpose(matrix , &matrix1);
    printf("\n\n");
    for( i = 1 ; i <= matrix1.len ; i ++){
        printf("%d %d %d\n" , matrix1.data[i].row , matrix1.data[i].col , matrix1.data[i].elem);
    }
    return 0;
}

/*
 malloc出错，尚未解决
 plus：
 还是自己原原本本搞清楚了写得快*/
/*
6 7
0 12 9 0 0 0 0
0 0 0 0 0 0 0
-3 0 0 0 0 14 0
0 0 24 0 0 0 0
0 18 0 0 0 0 0
15 0 0 -7 0 0 0
 */
