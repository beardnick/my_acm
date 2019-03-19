#include<stdio.h>
#define MAX_SIZE 100000


int a[MAX_SIZE] ;

// void print(int size){
   // int i;
     // for(i = 1; i <= size ; i ++){
       // printf("%d " , a[i]);
   // }
   // printf("\n");
// }


void sift(int root  , int size){
    int temp = a[root];
    int index , i , finish;
    index = root;
    i = index*2;
    finish = 0;
    while(i <= size && !finish){
        if(i + 1 <= size && a[i + 1] > a[i]) i = i + 1;
        if(a[i] <= temp)finish = 1;
        else{
                a[index] = a[i];
                index = i ;
                i = i*2;
        }
            }
        a[index] = temp;
}

void initHeap(int size){
    int i;
    for(i = size / 2 ; i >= 1 ; i--){
        sift(i , size);
    }
}

void heapSort(int size){
    initHeap(size);
 //   print(size);
    int i , temp;
    for(i = size ; i >= 2 ; i --){
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        sift(1 , i - 1);
  //      print(size);
    }
}

int main(){
    int i  , size;
    scanf("%d" , &size);
    for(i = 1 ; i <= size ; i ++){
        scanf("%d" , &a[i]);
    }
    heapSort(size);
    for(i = 1 ; i <= size ; i ++){
        printf("%d " , a[i]);
    }
    printf("\n");
    return 0;
}
