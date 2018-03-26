#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAXN = 110;
const int MAXM = 1000;
const long long MOD = 1000000007;
long long d[MAXN][MAXM];

int main(){
    int l , k;
    while(scanf("%d%d" , &k , &l) != EOF){
        long long sum = 0;
        memset(d , 0 , sizeof(d));
        for(int i = 0 ; i < k ; i ++){
            d[1][i] = 1;
        }
        for(int i = 2 ; i <= l ; i ++){
            for(int j = 0 ; j < k ; j ++){
                for(int m = 0 ; m < k ; m ++){
                    if( m != j + 1 && m != j - 1 ){
                        d[i][j] =( d [i][j] % MOD + d[i - 1][m] % MOD ) % MOD;
                    }
                }
            }
        }
        for(int i = 1 ; i < k ; i ++){
            sum = (sum % MOD + d[l][i] % MOD) % MOD;
        }
//        if(l == 1){
//            sum = (sum % MOD  + d[l][0] % MOD) % MOD;
//        }
        printf("%lld\n" ,sum);
    }

    return 0;
}
