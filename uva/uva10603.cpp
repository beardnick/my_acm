#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 205;

struct Node{
    int dist , v[3];
    bool operator < (const Node &x)const {
        return dist > x.dist;
    }
};

int vis[MAXN][MAXN];
int water[MAXN];

void up_grade(Node s){
    for(int i = 0 ; i < 3; i ++){
        int d = s.v[i];
        if(water[d] < 0 || s.dist < water[d])water[d] = s.dist;
    }
}

void solve(int a , int b , int c , int d){
    Node start;
    int capcity[3];
    capcity[0] = a;
    capcity[1] = b;
    capcity[2] = c;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = c;
    start.dist = 0;
    memset(vis , 0 , sizeof(vis));
    memset(water , -1 , sizeof(water));
    priority_queue<Node> q;
    q.push(start);
    vis[0][0] = 1;
    while(! q.empty()){
        Node u = q.top();
        q.pop();
        up_grade(u);
        // for(int i = 0 ; i < 3 ; i ++)
            // printf("%d " , u.v[i]);
        // printf("\n");
        if(water[d] >= 0)break;
        for(int i = 0 ; i < 3 ; i ++){
            for(int j = 0 ; j < 3 ; j ++){
                if(i != j){
                    if(u.v[i] == 0 || u.v[j] == capcity[j])continue;
                // int amount = min(capcity[j] , u.v[i] + u.v[j]) - u.v[j];
                // Node newU;
                // memcpy(&newU , &u , sizeof(u));
                // newU.v[i] -= amount;
                // newU.v[j] += amount;
                Node newU;
                memcpy(&newU , &u , sizeof(u));
                if(u.v[i] > capcity[j] - u.v[j]){
                    newU.v[j] = capcity[j];
                    newU.v[i] -= (capcity[j] - u.v[j]);
                    newU.dist = u.dist + capcity[j] - u.v[j];
                }else{
                    newU.v[i] = 0;
                    newU.v[j] += u.v[i];
                    newU.dist = u.dist + u.v[i];
                }
                if(! vis[newU.v[0]][newU.v[1]]){
                    q.push(newU);
                vis[newU.v[0]][newU.v[1]] = 1;
                }
                }
            }
        }
    }
    
    while(d >= 0){
        if(water[d] >= 0){
            printf("%d %d\n" , water[d] , d);
            return;
        }
        d --;
    }
}
int main(){
    int n , a , b , c , d;
    scanf("%d" , & n);
    while(n --){
        scanf("%d%d%d%d" , &a , &b , &c , &d);
        solve(a , b , c , d);
    }
    return 0;
}