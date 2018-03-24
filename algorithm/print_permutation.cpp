#include<iostream>
#include<cstdio>

using namespace std;

long long counter = 0;

void print_permutation(int n ,int *a , int cur){
    if(cur == n ){
            printf("%d:\t" , ++counter);
        for(int i = 0 ;i < n ; i ++){
            printf("%d " ,a[i] );
        }
        printf("\n");
    }else{

    }
    for(int i = 1 ; i <= n ;i ++){
        int ok = 1;
        for(int j = 0 ; j < cur;j ++){
            if(i == a[j]){
                    ok = 0;
                    break;
            }
        }
        if(ok){
            a[cur] = i;
            print_permutation(n , a , cur + 1);
        }
    }
}

int main(){
    int a[100];
    print_permutation(10 , a , 0);
    return 0;
}
