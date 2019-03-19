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

long long a , b;
int ans[MAXN] , res[MAXN];
int maxd;

int get_first(long long a , long long b){
    return b % a == 0 ? b / a : b / a + 1;
}


int get_last(int d , long long a , long long b){
    return((maxd - d) * b / a) + 1;
}

bool better(int d){
//    cout<<endl;
        printf("d>>%d\n")
    for(int i = 0 ;i <= d ;i ++){
//        cout<<ans[i]<<" ";
        if(ans[i] > res[i]){
            return res[i] != -1;
        }
    }
    return false;
}
bool dfs(int d , long long aa , long long bb){
    if(d == maxd){
        if(aa == 1){
            ans[d] = bb;
            if(better(d)){
                memcpy(res , ans , sizeof(ans));
            }
            return true;
        }
        return false;
    }
    bool ok = false;
    int from = get_first(aa , bb);
    int last = get_last(d , aa , bb);
//    printf("from>>%d last>>%d\n" , from , last);
    for(int i = from ; i <= last; i ++){
        ans[d] = i;
        int newa = aa * i - b;
        int newb = bb * i;
        int t = __gcd(newa , newb);
        if(dfs(d + 1 , newa / t , newb / t)){
            ok = true;
        };
    }
    return ok;
}
int main(){
    while(scanf("%lld%lld" , &a , &b) != EOF){
        memset(res , -1 , sizeof(res));
        for(maxd = 1 ;; maxd ++){
            memset(ans , -1 , sizeof(ans));
            if(dfs(0 , a , b)){
                break;
            };
        }
        for(int i = 0 ;res[i] != -1 ;i ++){
            cout<<res[i]<<" ";
        }
    }
    return 0;
}
