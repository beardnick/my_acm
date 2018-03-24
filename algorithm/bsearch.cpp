#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 65535;

int bsearch(int *a , int x , int y , int v){
    int m;
    while(x < y){
        m = x + (y - x) / 2;
        if(a[m] == v)return m;
        else if(a[m] > v) y = m;
        else x = m + 1;
    }
    return -1;
}

int lower_bound(int *a , int x , int y , int v){
    int m , find = 0;
    while(x < y){
        m = x + (y - x) / 2;
        if(a[m] >= v){
            y = m;
            if(a[m] == v)find = 1;
        }
        else x = m + 1;
    }
    if( ! find)return -1;
    return x;
}

int upper_bound(int *a , int x , int y , int v){
    int m , find = 0;
    while(x < y){
        m = x + (y - x) / 2;
        if(a[m] == v) {
            x = m;
            find = 1;
            if(y - x == 1)break;
        }
        else if(a[m] > v) y = m;
        else x = m + 1;
    }
    if( ! find)return -1;
    return x;
}

int main(){
     int a[N] , n , v;
     while(scanf("%d%d" , &n , &v) != EOF){
        for(int i = 0 ; i < n ; i ++){
         scanf("%d" , &a[i]);
        }
        sort(a , a + n);
        for(int i = 0 ; i < n ; i ++){
            printf("%d " , a[i]);
        }
        printf("\n"); 
        printf("%d\n" , upper_bound(a , 0 , n , v));
     }
    return 0;
}