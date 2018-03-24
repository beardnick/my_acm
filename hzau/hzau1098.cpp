#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
long long x = 1;
const long long INF = (x << 62);
const int MAXN = 300;
long long a[MAXN];
long long d[MAXN][MAXN];
int n;
long long  dp(int i , int j){
    if(i == j - 1){

//    printf("d[%d][%d]>>%lld\n" , i , j , 0);
        return d[i][j] = 0;
    }
    long long& ans = d[i][j];
    if(ans >= 0 ){
//    printf("d[%d][%d]>>%lld\n" , i , j , ans);
        return ans;
    }
    ans = INF;
    for(int k = i + 1 ; k < j ; k ++){
         ans = min(ans , dp(i , k) + dp(k , j) + a[i] + a[k] + a[j]);
    }
//    printf("d[%d][%d]>>%lld\n" , i , j , ans);
    return ans;
}
int main(){
    while(scanf("%d" , &n) != EOF){
    for(int i = 1 ; i <= n ; i ++){
        scanf("%lld" , &a[i]);
    }
    memset(d , -1 , sizeof(d));
    a[0] = a[n + 1] = 0;
//    printf("INF>>%lld\n" , INF);
    cout<<dp(0 , n + 1)<<endl;
    }
    return 0;
}
