#include <stdio.h>
#define  MAX_SIZE 100

//indeg in degree , a store the sorted list
int indeg[MAX_SIZE] , size , sorted[MAX_SIZE] = {0} , a[MAX_SIZE] , counter = 0;
int graph[MAX_SIZE][MAX_SIZE];

void build(){
    int i , j ;
    for(i = 0 ; i < size ; i ++){
        for( j = 0 ; j < size ; j ++){
            if(graph[i][j])indeg[j] ++;
        }
    }

}

void sort(int i){
    int j;
    for( ; i >= 0 ; i --){
        if (indeg[i] == 0 && ! sorted[i]) {
            a[counter ++] = i;
            sorted[i] = 1;
            for(j = 0 ; j < size ; j ++){
                if(graph[i][j]){
                    indeg[j] --;
                    if(! indeg[j])sort(j);
                }
            }
        }
    }
}

int main(){
    int i , j;
    scanf("%d" , &size);
    for( i = 0 ; i < size ; i ++){
        for(j = 0 ; j < size ; j ++){
            scanf("%d" , &graph[i][j]);
        }
    }
    build();
    sort(size - 1);
    int flag = 1;
    for( i = 0 ; i < size ; i ++){
        if(indeg[i])flag = 0;
    }
    if(flag){
        for(i = 0 ; i < size ; i ++){
            printf("%d " , a[i]);
        }
        printf("\n");
    } else{
        printf("ERROR\n");
    }
    return 0;
}