#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
const int INF = (1 << 30);
const int MAXN = 15;
int vis[MAXN][MAXN] , res;
int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
int m , n;
int a[MAXN][MAXN];

void search(int x , int y , int cur , int counter){
    if(x < 1 || y < 1 || x > n || y > m || cur < 0){
        return;
    }
    if(cur == 0){
        if(counter < res){
            res = counter;
        }
        return;
    }
//    printf("(%d , %d)\n" , x , y);
    for(int i = 0 ; i < 4 ; i ++){
        int tempx = x + dx[i] ,tempy = y + dy[i];
        if(! vis[tempx][tempy]){
            vis[tempx][tempy] = 1;
            search(tempx , tempy , cur - a[tempx][tempy] , counter + 1);
            vis[tempx][tempy] = 0;
        }
    }
}
int main(){
    int sum;
    while(scanf("%d%d" , &m , &n) != EOF){
        sum = 0;
        memset(vis , 0 , sizeof(vis));
        res = INF;
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= m ; j ++){
                scanf("%d" , &a[i][j]);
                sum += a[i][j];
            }
        }
        if(sum % 2 == 0){
            vis[1][1] = 1;
            search(1 , 1 , sum / 2 - a[1][1] , 1);
            cout<<res<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
