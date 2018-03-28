#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
const int INF = (1 << 30);
const int MAXN = 1000;
int tot = 0;
int a[MAXN][MAXN];
int vis[MAXN][MAXN];

void dfs(int x , int y ){
    if(x < 1 || y < 1 || y > 10 || x > 10){
        tot ++;
        return;
    }
    if(vis[x][y]){
        return ;
    }
    vis[x][y] = 1;
    switch(a[x][y]){
        case 'U' :
            dfs(x , y - 1 );
            break;
        case 'D' :
            dfs(x , y + 1 );
            break;
        case 'L' :
            dfs(x - 1 , y );
            break;
        case 'R' :
            dfs(x + 1 , y );
            break;
    }
    vis[x][y] = 0;
}
int main(){
    for(int i = 1 ; i <= 10 ; i ++){
        for(int j = 1 ;j <= 10 ;j ++){
            scanf("%c" , &a[j][i]);
            if(a[j][i] != 'U' && a[j][i] != 'D' && a[j][i] != 'L' && a[j][i] != 'R'){
                j --;
            }
        }
    }
    for(int i = 1 ; i <= 10 ; i ++){
        for(int j = 1 ;j <= 10 ;j ++){
            printf("%c " , a[j][i]);
        }
        cout<<endl;
    }
    for(int i = 1 ; i <= 10 ; i ++){
        for(int j = 1 ;j <= 10 ; j ++){
//            memset(vis , 0 , sizeof(vis));
            dfs(i , j );
        }
    }
    cout<<tot<<endl;
    return 0;
}
