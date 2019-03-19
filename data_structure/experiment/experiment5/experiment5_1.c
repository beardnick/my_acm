#include <stdio.h>
#define MAX_SIZE 1000
int a[MAX_SIZE] ;

int binarySearch(int low , int high , int target){
    if(low > high)return -1;
    int mid = (low + high)/2;
    if(target == a[mid]){
        int i = mid - 1;
        while(i >= 0 &&a[i] == a[mid])i--;
        return i + 1;
    }
    else if(target > a[mid])return binarySearch(mid + 1 , high , target);
    else if(target < a[mid])return binarySearch(low , mid - 1 , target);
}

int main(){
    int n , k;
    int i , target;
    scanf("%d%d" , &n , &k);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
    }
    while (k --){
        scanf("%d" , &target);
        printf("%d " , binarySearch(0 , n -1  , target));
    }
    printf("\n");
    return 0;
}
