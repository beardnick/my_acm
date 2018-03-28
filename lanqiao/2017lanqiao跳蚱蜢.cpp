#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
const int INF = (1 << 30);
const int MAXN = 10000000;
typedef int state[9];
state st[MAXN];
int dx[5] = {-2 , -1 , 1 , 2};
int dist[MAXN];
set<int> vis;

int can_insert(state s){
    int code = 0;
    for(int i = 1 , j = 1 ; i <= 9 ;i ++ , j *= 10){
        code += s[i] * j;
    }
    if(vis.count(code)){
        return 0;
    }
    vis.insert(code);
    return 1;
}

int bfs(){
    state s , goal;
    for(int i = 1 ;i <= 8 ; i ++){
        goal[i] = 9 - i;
    }
    goal[0] = 0;
    int front = 1 , rear = 2;
    for(int i = 0 ;i <= 8 ; i ++){
        s[i] = i;
    }
    memcpy(&st[front] , &s , sizeof(s));
    dist[front] = 0;
    can_insert(st[front]);
    while(rear > front){
        int cur;
        state& t = st[front];
        if(memcmp(goal , t , sizeof(t)) == 0){
            return front;
        }
        for(int i = 0 ;i <= 9 ; i ++){
            if(t[i] == 0){
                cur = i;
                break;
            }
        }
        for(int i = 0 ; i <= 4 ;i ++){
            state& ns = st[rear];
            memcpy(&ns , &t , sizeof(t));
            int tcur = cur + dx[i];
            if(tcur < 0 ){
                tcur = 9 + tcur;
            }else{
                tcur = tcur % 9;
            }
            ns[cur] = ns[tcur];
            ns[tcur] = 0;
            if(can_insert(ns)){
                dist[rear] = dist[front] + 1;
                rear ++;
            }
        }
        front ++;
    }
    return 0;
}

int main(){
    vis.clear();
    int front = bfs();
    if(front){
        cout<<dist[front]<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}
