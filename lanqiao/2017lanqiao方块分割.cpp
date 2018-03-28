#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
const int INF = (1 << 30);
const int MAXN = 100;
const int N = 7;
int dx[5] = {0 , 0 , -1 , 1};
int dy[5] = {1 , -1 , 0 , 0};
int tot = 0 , d[MAXN][MAXN];

//深搜格子只能搜出一笔画出的范围
void dfs(int x , int y ){
    if(x == 1 || y == 1 || y == N || x == N){
        tot ++;
//        cout<<"test"<<tot<<endl;
//        for(int i = 1 ; i <= N ; i ++){
//            for(int j = 1 ; j <= N ; j ++){
//                printf("%d " , d[i][j]);
//            }
//            cout<<endl;
//        }
//        cout<<endl<<endl;
        return ;
    }
    for(int i = 0 ; i < 4 ; i ++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(d[tx][ty] != 0){
                continue;
            }else{
                d[tx][ty] = 1;
                d[N - tx + 1][N - ty + 1] = 1;
                dfs(tx , ty );
                d[tx][ty] = 0;
                d[N - tx + 1][N - ty + 1] = 0;
            }
    }
}
int main(){
    memset(d , 0 , sizeof(d));
    d[N / 2 + 1][N / 2 + 1] = 1;
    dfs(N / 2 + 1 , N / 2 + 1 );
    if(tot % 4 == 0){
        cout<<(tot / 4)<<endl;
    }else{
        cout<<"tot>>"<<tot<<endl;
    }
    return 0;
}
