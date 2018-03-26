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
int  maxn , d[MAXN];
int dp(int p ,int gp){
    int ans1 = -INF;
    int ans2 = -INF;
    for(int i = 0 ; i < a[p].size() ; i ++){
        int temp = a[p][i];
        if(temp != gp){
            if(dp(temp , p) >= ans1){
                ans2 = ans1;
                ans1 = d[temp];
            }else{
                ans2 = max(ans2 , d[temp]);
            }
        }
    }
    ans1 = (ans1 == -INF ? -1 : ans1);
    ans2 = (ans2 == -INF ? -1: ans2);
    if(ans1 + ans2 + 2 > maxn){
        maxn = ans1 + ans2 + 2;
    }
    printf("d[%d]>>%d\n" , p , ans1 + 1);
    return d[p] = ans1 + 1;
}

int main(){
    int tempa , tempb ;
    while(scanf("%d"  , &n)  != EOF){
        for(int i = 1 ; i <= n - 1; i ++){
            scanf("%d%d" , &tempa , &tempb);
            a[tempa].push_back(tempb);
            a[tempb].push_back(tempa);
        }
        memset(d , 0 , sizeof(d));
        maxn = -INF;
        dp(1 , -1);
        cout<<maxn<<endl;
        for(int i = 1 ; i <= n ; i ++){
            a[i].clear();
        }
    }
    return 0;
}
