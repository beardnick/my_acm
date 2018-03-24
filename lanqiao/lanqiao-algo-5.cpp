#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
const int INF = 65535;
const int MAXN = 20010;
int vis[MAXN] , dist[MAXN];

class node{
  public:
    int v , w;
    node(int v , int w):v(v) , w(w){}
    node(){}
};
vector<vector<node> > graph(MAXN , vector<node>(0));
// list<node> graph[MAXN];
class triple{
  public:
    int i , v;
    triple(int i , int v):i(i),v(v){}
    triple(){}
    bool operator < (const triple& x)const{
        return v > x.v;
    }
};

void dfs(int n){
    int s = 1;
    int m = n - 1;
    vis[s] = 1;
    dist[s] = 0;
    vector<node>::iterator it;
    while(m --){
        priority_queue<triple> q; 
        for(it = graph[s].begin();it != graph[s].end() ; it ++){
        if(vis[(*it).v] == 0){
            dist[(*it).v] = min(dist[s] + (*it).w , dist[(*it).v]);
            q.push(triple((*it).v , dist[(*it).v]));
        }
    }
    s = q.top().i;
    vis[s] = 1;
    }
}

int main(){
    int n , m;
    int x , y, w;
    while(scanf("%d%d" ,&n , &m) != EOF){
    for(int i = 0 ; i< MAXN;i ++){
        dist[i] = INF;
        vis[i] = 0;
    }
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d" , &x , &y , &w);
        graph[x].push_back(node(y , w));
    }
    dfs(n);
    for(int i = 2 ; i <= n;i ++){
        printf("%d\n" , dist[i]);
    }  
    }

    return 0;
}