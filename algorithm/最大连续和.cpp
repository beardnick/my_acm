#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10000;
int n;

//完全暴力算出连续子序列和
//O(n^3)
// int max_sum(int *a){
    // int best = a[0];
    // for(int i = 0 ; i < n ; i ++){
        // for(int j = i ; j < n ; j ++){
            // int sum = 0;
            // for(int k = i ; k <= j ; k ++){
                // sum += a[k];
            // }
            // if(sum > best)best = sum;
        // }
    // }
    // return best;
// }

//利用数列前n项和公式算出子序列和
//O(n^2)
// int max_sum(int *a){
    // int S[N];
    // S[0] = a[0];
    // for(int i = 1 ; i < n ; i ++){
        // S[i] = S[i - 1] + a[i];
    // }
    // int best = S[0];
    // for(int i = 0 ; i < n ; i ++){
        // for(int j = i ; j < n ; j ++){
            // if(S[j] - S[i] + a[i] > best)best = S[j] - S[i] + a[i];
        // }
    // }
    // return best;
// }

//分治算法
//O(nlgn)
// int max_sum(int *a , int x , int y){
    // if(y - x == 1)return a[x];
    // int m , maxs;
    // m = (x + y) / 2;
    // maxs = max(max_sum(a , x , m) , max_sum(a , m , y));
    // int temp , maxl , maxr;
    // maxl = a[m - 1];
    // maxr = a[m];
    // temp = 0;
    // for(int i = m - 1; i >= x ; i --){
        // maxl = max(maxl , temp += a[i]);
    // }
    // temp = 0;
    // for(int i = m ; i < y ; i ++){
        // maxr = max(maxr , temp += a[i]);
    // }
    // return max(maxl + maxr , maxs);
// }

//逆向思维，j确定时 ， s[j] - s[i]最大， s[i]肯定是当前最小的
//O(n)
int max_sum(int *a){
    int mins , maxs , sum;
    mins = maxs = sum = 0; 
    for(int i = 0 ; i < n ; i ++){  
        mins = min(mins , sum += a[i]);
        maxs = max(maxs , sum - mins);
    }
    return maxs;
}

int main(){
    int a[N];
    while(scanf("%d" , &n) != EOF && n){
         for(int i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
        }
        printf("%d\n" , max_sum(a));
    }
    return 0;
}