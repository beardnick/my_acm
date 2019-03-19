#include <stdio.h>

#define MAX_SIZE 1000
int a[MAX_SIZE] ;

int binarySearch(int low , int high , int target){
    if(low > high)return low;
    int mid = (low + high)/2;
    if(target == a[mid])return mid;
    else if(target > a[mid])return binarySearch(mid + 1 , high , target);
    else if(target < a[mid])return binarySearch(low , mid - 1 , target);
}

void move(int from , int to){
    int temp = a[from];
    int i;
    for(i = from ; i > to ; i --){
        a[i] = a[i - 1];
    }
    a[to] = temp;
}

int main(){
    int n , i;
    scanf("%d" , &n);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
    }
    for( i = 1 ; i < n; i ++){
        move(i , binarySearch(0 , i - 1 , a[i]));
    }
    for(i = 0 ; i < n ; i ++){
        printf("%d " , a[i]);
    }
    return 0;
}