//
// Created by asus on 2017/10/16.
//

#ifndef DATASTRUCTURE_TSMATRIX_H
#define DATASTRUCTURE_TSMATRIX_H

#include <stdio.h>

#define MAX_SIZE 100
#define N 10

#define T int

typedef struct {
    int row , col;
    T elem;
}Triple;

typedef struct{
    Triple data[MAX_SIZE];
    int rowNum , colNum , len;
}TSMatrix;

void Init(TSMatrix *matrix){
    matrix->len = matrix->colNum = matrix->rowNum = 0;
}

//build the TSMatrix
//the data[0] wont use

int build(TSMatrix *matrix , T a[N][N] , int row , int col){
    matrix->rowNum = row;
    matrix->colNum = col;
    if(a == NULL || row <= 0 || col <= 0 ){
        return 0;
    }
    int i , j;
    for( i = 0 ; i < row ; i ++){
        for(j = 0 ; j < col ; j ++){
            if(a[i][j] != 0){
                matrix->len ++;
                matrix->data[matrix->len].elem = a[i][j];
                matrix->data[matrix->len].row = i + 1;
                matrix->data[matrix->len].col = j + 1;
            }
        }
    }
    return 1;
}

//transpose the matrix

int Transpose(TSMatrix from , TSMatrix *to){
    int position[MAX_SIZE] = {0};
    int i;
    to->colNum = from.rowNum;
    to->rowNum = from.colNum;
    to->len = from.len;
    for(i = 1 ; i <= from.len ; i ++){
        position[from.data[i].col + 1] ++;
    }
    position[1] = 1;
    for(i = 2 ; i <= from.len ; i ++){
        position[i] += position[i - 1];
    }
    int col , tempPosition;
    for(i = 1 ; i <=from.len ; i ++){
        col = from.data[i].col;
        tempPosition = position[col];
        to->data[tempPosition].elem = from.data[i].elem;
        to->data[tempPosition].col = from.data[i].row;
        to->data[tempPosition].row = from.data[i].col;
        position[col] ++;
    }
    return 1;
}

void PrintMatrix(TSMatrix matrix){
    int i , j;
    int counter = 1;
    for(i = 0 ; i < matrix.rowNum ; i ++){
        for( j = 0 ; j < matrix.colNum ; j ++){
            if(i + 1 == matrix.data[counter].row && j + 1== matrix.data[counter].col ){
                printf("%d " , matrix.data[counter].elem);
                counter ++;
            } else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    TSMatrix matrix;
    Init(&matrix);
    int a[N][N];
    int row , col;
    scanf("%d%d" , &row , &col);
    int i , j;
    for(i = 0 ; i < row ; i ++){
        for(j = 0 ; j < col ; j ++){
            scanf("%d" , &a[i][j]);
        }
    }
    build(&matrix , a , row , col);
    TSMatrix toMatrix;
    Init(&toMatrix);
    Transpose(matrix ,&toMatrix );
    PrintMatrix(toMatrix);
    return 0;
}



#endif //DATASTRUCTURE_TSMATRIX_H
