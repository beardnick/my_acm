#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<stack>

using namespace std;
typedef int State[9];
const int MAXN = 1000000;
State st[MAXN];
State goal;
int dist[MAXN];
int dx[4] = {-1 , 1 , 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};
int fa[MAXN];
set<int> table;
int vis[362880];// 9 ! + 1 = 362880
int fact[9];
// void init_lookup_table(){
    // table.clear();
// }

// int try_to_insert(int rear){
    // int value = 0;
    // for(int i = 0 ; i < 9 ; i ++){
        // value  = value * 10 + st[rear][i];
    // }
    // if(table.count(value))return 0;
    // table.insert(value);
    // return 1;
// }

void init_lookup_table(){
    fact[0] = 1;
    for(int i = 1 ; i < 9 ; i ++){
        fact[i] = fact[i - 1] * i;
    }
}

int try_to_insert(int rear){
    int code = 0;
    for(int i = 0 ; i < 9 ; i ++){
        int cnt = 0;
        for(int j = i + 1 ; j < 9 ; j ++){
            if(st[rear][j] < st[rear][i])
                cnt ++;
        }
        code += fact[8 - i] * cnt;
    }
    if(vis[code])return 0;
    return vis[code] = 1;
}
int bfs(){
    int front = 1 , rear = 2;
    int x , y , newx , newy , newz;
    // memset(st , 0 , sizeof(st));
    // memset(fact , 0 , sizeof(fact));
    // memset(dist , 0 , sizeof(dist));
     memset(vis , 0 , sizeof(vis));
    init_lookup_table();
    try_to_insert(1);
    while(front <rear){
        State& s = st[front];
       // printf("%d\n" , front);
        if(memcmp(goal , s , sizeof(s)) == 0){return front;}
        int z;
        for(z = 0 ; z < 9 ; z ++){if(! s[z]) break;}
        x = z % 3;
        y = z / 3;
        for(int i = 0 ; i < 4 ; i ++){
            newx = x + dx[i];
            newy = y + dy[i];
            if(newx >= 0 && newx <= 2 && newy >= 0 && newy <= 2){
                newz = 3 * newy + newx;
                State& t = st[rear];
                memcpy(&t , &s , sizeof(s));
                t[z] = s[newz];
                t[newz] = s[z];
                dist[rear] = dist[front] + 1;
                if(try_to_insert(rear)){
                    fa[rear] = front;
                    rear ++;
                }
            }
        }
        front ++;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d" , &n);
    while(n --){
        for(int i = 0 ; i < 9 ; i ++)scanf("%d" , &st[1][i]);
    for(int i = 0 ; i < 9 ; i ++)scanf("%d" , &goal[i]);
    dist[1] = 0;
    int result = bfs();
    //printf("%d\n" , result);
    if(result) {
        printf("%d\n" , dist[result]);
          // stack<int>path;
          // path.push(result);
    // while(fa[result] != 0){
        // result = fa[result];
        // path.push(result);
    // }
    // while(! path.empty()){
        // for(int i = 0 ; i < 9 ; i ++){
            // if(i && i % 3 == 0)printf("\n");
            // printf("%d " , st[path.top()][i]);
        // }
        // printf("\n\n");
        // path.pop();
    // }
    }
    else printf("-1\n");
    }
    return 0;
}

/* 2 6 4 1 3 7 0 5 8
2 6 4 1 3 0 7 5 8 */

/* 2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2 */


