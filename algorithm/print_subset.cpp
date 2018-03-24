#include<iostream>
#include<cstdio>

using namespace std;

long long counter = 0;

void bi_print_subset(int n , int s){
    printf("%d:\t" , ++counter);
    for(int i = 0 ;i < n ; i ++){
        if(s&(1<<i)){//扫描二进制位，为1就输出
            printf("%d " , i + 1);
        }
    }
    printf("\n");
}


void bin_print_subset(int n){
      for(int i = 0 ;i < (1<<n) ;i ++)//生成0到2^n - 1的数，对应子集二进制编码
        bi_print_subset(n , i);
}

//void print_subset(int n , int *a , int cur){
//    if(cur == n){
//            printf("%d:\t" , ++counter);
//        for(int i = 0 ;i < n ;i ++){
//            if(a[i])printf("%d " , i + 1);
//        }
//        printf("\n");
//        return;
//    }
//    a[cur] = 1;
//    print_subset(n , a , cur + 1);
//    a[cur] = 0;
//    print_subset(n , a , cur + 1);
//}

//void print_subset(int n , int *a , int cur){
//    printf("%d:\t" , ++counter);
//    for(int i = 0 ;i <cur ;i ++){
//        printf("%d " , a[i] + 1);
//    }
//    printf("\n");
//    int s = cur?a[cur - 1] + 1: 0;
//    for(int i = s; i < n ;i ++){
//        a[cur] = i;
//        print_subset(n , a , cur + 1);
//    }
//
//}

int main(){
    int a[100];
    //print_subset(5 , a , 0);
    bin_print_subset(5);
    return 0;
}
