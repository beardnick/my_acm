#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = (1 << 30);
const int MAXN = 2000;
char a[MAXN];
int dp[MAXN][MAXN] , d[MAXN];
int main(){
    a[0] = '1';
    int n;
    scanf("%d" , &n);
    while(n -- ){
        getchar();
        scanf("%s" , a + 1);
        for(int i = 1 ; i < strlen(a) ; i ++){
            dp[i][i] = 1;
            for(int j = 1 ; j <= i - 1 ; j ++){
                if(a[i] == a[j]){
                if(j == i - 1){
                    dp[j][i] = 1;
                }else{
                    dp[j][i] = dp[j + 1][i - 1];
                }

                }else{
                    dp[j][i] = 0;
                }
//       printf("dp[%d][%d]>>%d\n" , j , i , dp[j][i]);
            }
}
                d[0] = 0;
                for(int i = 1 ; i < strlen(a) ; i ++){
                    int temp = INF;
                    for(int j = 0 ; j < i ; j ++){
                        if(dp[j + 1][i] && d[j] < temp){
                            temp = d[j];
                        }
                    }
                    d[i] = temp + 1;
//                   printf("d[%d]>>%d\n" , i , d[i]);
                }
//        cout<<strlen(a) - 1<<endl;
        cout<<d[strlen(a) - 1]<<endl;
    }
    return 0;
}
