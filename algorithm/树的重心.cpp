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
int n;
vector<int> a[MAXN];
int res , minn , d[MAXN];
int dp(int p ,int gp){
    int ans = -INF;
    for(int i = 0 ; i < a[p].size() ; i ++){
        int temp = a[p][i];
        if(temp != gp){
            ans = max(ans , dp(temp , p));
            d[p] += d[temp];
        }
    }
    d[p] += 1;
    if(max(n - d[p] , ans) < minn){
        minn = max(n - d[p] , ans);
        res = p;
    }
    return d[p];
}

int main(){
    int tempa , tempb , m;
    while(scanf("%d%d"  , &n , &m) != EOF){
        while(m --){
            scanf("%d%d" , &tempa , &tempb);
            a[tempa].push_back(tempb);
            a[tempb].push_back(tempa);
        }
        memset(d , 0 , sizeof(d));
        minn = INF;
        dp(1 , -1);
        cout<<res<<endl;
        for(int i = 1 ; i <= n ; i ++){
            a[i].clear();
        }
    }
    return 0;
}
