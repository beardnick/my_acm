#include <stdio.h>

#define MAX_SIZE 100000
int a[MAX_SIZE] ;

void shellSort(int begin , int end){
    int d ;
    int temp , i , j;
    for (d= (end - begin)/2; d >=1 ;d = d/2){
            for(i = d ; i <= end ; i ++){
                temp = a[i];
                for( j = i ; j >= begin + d; j -= d){
                    if(a[j - d] > temp) a[j] = a[j - d];
                    else break;
                }
                a[j] = temp;
            }
    }
}

void insertSort(int begin , int end){
    int temp , i , j;
    for(i = begin + 1; i <= end ; i ++){
        temp = a[i];
        for( j = i ; j >= begin + 1; j --){
            if(a[j - 1] > temp) a[j] = a[j - 1];
            else break;
        }
        a[j] = temp;
    }
}

int main(){
    int n , i;
    scanf("%d" , &n);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
    }
    //insertSort(0 , n - 1);
    shellSort(0 , n - 1);
    for(i = 0 ; i < n ; i ++){
        printf("%d " , a[i]);
    }
    printf("\n");
    return 0;
}