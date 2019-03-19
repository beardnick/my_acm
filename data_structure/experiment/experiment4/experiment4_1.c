#include <stdio.h>


#define MAX_SIZE 100
int vis[MAX_SIZE] = {0};
int graph[MAX_SIZE][MAX_SIZE];

void search(int i , int size){
    int j;
    for( j = 0 ; j < size ; j ++){
        if(graph[i][j] && ! vis[j]){
            printf(" %d " , j);
            vis[j] = 1;
            search(j , size);
        }
    }
}

int main(){
    int size ;
    scanf("%d" , &size);
    int i , j;
    for(i = 0 ; i < size ; i ++){
        for ( j = 0 ; j < size ; j ++){
            scanf("%d" , &graph[i][j]);
        }
    }
    printf("0 ");
    vis[0] = 1;
    search(0 , size);
    printf("\n");
    return 0;
}