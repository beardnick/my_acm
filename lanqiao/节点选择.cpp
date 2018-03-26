#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int MAXN = 100010;
vector<int> g[MAXN];
int weight[MAXN] , d[MAXN] , s[MAXN] , gs[MAXN];
int dp(int p , int gp){
    if(d[p] != -1){
        return d[p];
    }
    for(int i = 0 ; i < g[p].size() ; i ++){
        int temp = g[p][i];
        if(temp != gp){
            s[p] += dp(temp , p);
            for(int j = 0 ; j < g[temp].size() ; j ++){
                int temps = g[temp][j];
                if(temps != p){
                    gs[p] += dp(temps , temp);
                }
            }
        }
    }
    return d[p] = max(s[p] , gs[p] + weight[p]);
}
int main(){
    int n , tempa , tempb;
    while(scanf("%d" , &n) != EOF){
        for(int i = 1 ;i <= n ; i ++){
            scanf("%d" , &weight[i]);
        }
        for(int i = 1 ; i <= n - 1 ; i ++){
            scanf("%d%d" , &tempa , &tempb);
            g[tempa].push_back(tempb);
            g[tempb].push_back(tempa);
        }
        memset(d , -1 , sizeof(d));
        memset(s , 0 , sizeof(s));
        memset(gs , 0 , sizeof(gs));
        cout<<dp(1 , -1)<<endl;
        for(int i = 1; i <= n; i ++){
            g[i].clear();
        }
    }
    return 0;
}
