#include <stdio.h>

#define MAX_SIZE 100000
int a[MAX_SIZE]  , help[MAX_SIZE/2 + 1];

void merge(int low , int mid , int high){
    int i , j , k;
    i = low ; j = mid + 1 ; k = 0;
    while (i <= mid && j <= high){
        if(a[i] < a[j]){
            help[k ++] = a[i ++];
        } else{
            help[k ++] = a[j ++];
        }
    }
    while (i <= mid)
        help[k ++] = a[i ++];
    while (j <= high)
        help[k ++] = a[j ++];
    k --;
    for(i = high ; i >= low && k >=0; i -- , k --)
        a[i] = help[k];
}

void mergeSort(int begin , int end){
    if(begin < end){
        mergeSort(begin , (begin + end) / 2);
        mergeSort((begin + end) / 2 + 1 , end);
        merge(begin , (begin + end) / 2 , end);
    }
}

int main(){
    int n , i;
    scanf("%d" , &n);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
    }
    //insertSort(0 , n - 1);
   // shellSort(0 , n - 1);
    mergeSort(0 , n - 1);
    for(i = 0 ; i < n ; i ++){
        printf("%d " , a[i]);
    }
    printf("\n");
    return 0;
}