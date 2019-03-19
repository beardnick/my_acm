#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
const int INF = (1 << 30);
const int MAXN = 100000;

struct node{
    int v[3];
    int dist;
    //运算符重载要注意，要用很多const来限制
    bool operator < (const node& n)const {
        return dist > n.dist;
    }
};
int vis[400][400] , water[400];
void up_grade(node n){
    for(int i = 0 ;i < 3; i ++){
        int d = n.v[i];
        if(water[d] == -1 || n.dist < water[d]){
            water[d] = n.dist;
        }
    }
}
void solve(int a , int b , int c , int d){
    int cap[3] = {a , b , c};
    //priority_queue是必须的，因为是要倒的水最少
    //使用一般的queue是步数最少
    priority_queue<node> q;
    node start;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = cap[2];
    start.dist = 0;
    q.push(start);
    vis[0][0] = 1;
    while(! q.empty()){
        node n = q.top();
        q.pop();
        up_grade(n);
        for(int i = 0 ; i < 3 ;i ++){
            for(int j = 0 ; j < 3 ; j ++){
                node newn;
                memcpy(&newn , &n , sizeof(n));
                //自己不往自己里面倒水，i杯不是空的，j杯不是满的
                if(i != j && n.v[i] !=0 && n.v[j] != cap[j]){
                    if(n.v[i] <= cap[j] - n.v[j]){
                        newn.v[i] = 0;
                        newn.v[j] = n.v[i] + n.v[j];
                        newn.dist = n.dist + n.v[i];
                    }else{
                        newn.v[i] = n.v[i] - (cap[j] - n.v[j]);
                        newn.v[j] = cap[j];
                        newn.dist = n.dist + cap[j] - n.v[j];
                    }
                    //1 2 3 和 3 2 1 是不是等效的
                    //1 2 3 和 3 2 1 可不可能发生
                    //不可能，至少有一杯是空的或者有一杯是满的
                    //但是仍有可能出现0 1 2 ， 1 0 2 ，2 1 0的情况
//                    if(! vis[newn.v[i]][newn.v[j]]){
                    if(! vis[newn.v[0]][newn.v[1]]){
                        q.push(newn);
                        vis[newn.v[0]][newn.v[1]] = 1;
                    }
                }
            }
        }
    }
    for(int i = d ;i >= 0 ;i --){
        if(water[i] != -1){
            cout<<water[i]<<" "<<i<<endl;
            return;
        }
    }
}
int main(){
    int a , b , c , d;
    int n;
    scanf("%d" , &n);
    while(n --){
        scanf("%d%d%d%d" , &a , &b , &c , &d);
        memset(vis , 0 , sizeof(vis));
        memset(water , -1 , sizeof(water));
        solve(a , b , c , d);
    }
    return 0;
}
