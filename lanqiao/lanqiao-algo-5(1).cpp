#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int INF = 65535;
const int MAXN = 20010;
int vis[MAXN] , dist[MAXN];
int graph[MAXN][MAXN];


void dfs(int n){
    int s = 1;
    int m = n - 1;
    vis[s] = 1;
    dist[s] = 0;
    while(m --){
       for(int i = 1 ; i <= n ; i ++){
        if(graph[s][i] != INF && vis[i] == 0){
            dist[i] = min(dist[s] + graph[s][i] , dist[i]);
        }
    }
    int min = INF;
    for(int i = 2 ; i <= n ; i ++){
        if(vis[i] == 0 && dist[i] < min){
            min = dist[i];
            s = i;
        }
    }
    vis[s] = 1;
    }
}
int main(){
    int n , m;
    int x , y, w;
    for(int i = 0 ; i< MAXN;i ++){
        dist[i] = INF;
        vis[i] = 0;
        for(int j = 0 ; j <= MAXN ; j ++){
            graph[i][j] = INF;
        }
    }
    scanf("%d%d" ,&n , &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d" , &x , &y , &w);
        graph[x][y] = w;
    }
    dfs(n);
    for(int i = 2 ; i <= n;i ++){
        printf("%d\n" , dist[i]);
    }
    return 0;
}