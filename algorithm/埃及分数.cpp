#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 10000;
int maxd;
ll ans[MAXN] , v[MAXN];

int get_first(ll a , ll b){
    int c;
    for(c = 1 ;a * c < b; c ++);
    return c;
}

int gcd(ll x , ll y){
    if(y == 0)return x;
    return gcd(y , x % y);
}

bool better(int d){
    for(int i = d;i >= 0 ; i --){
        if(v[i] != ans[i]){
            return ans[i] == -1 || v[i] < ans[i];
        }
    }
    return false;
}

bool dfs(int d , int from , ll aa , ll bb){
    if(d == maxd){
        if(bb % aa)return false;
        v[d] = bb / aa;
        if(better(d)){
            memcpy(ans , v , sizeof(ll)*(d + 1));
        }
        return true;
    }
    from = max(from , get_first(aa , bb));
    bool ok = false;
    for(int i = from ;; i ++){
        //如果接下来所有的数都是1/i都小于aa/bb，则无解
        if(aa * i >= bb * (maxd + 1 - d))break;
        v[d] = i;
        int newaa = aa * i - bb;
        int newbb = bb * i;
        int g = gcd(newaa , newbb);
        if(dfs(d + 1 , i + 1 , newaa / g , newbb / g)){
            ok = true;
            //要把这一层结点全部遍历完才结束
            // break;
        }
    }
    return ok;
}

int main(){
    int a , b , ok = 0 , counter = 0;
    while(scanf("%d%d" , &a , &b) != EOF){
        for(maxd = 1 ; ; maxd ++){
        ok = 0;
        memset(ans , -1 , sizeof(ans));
        if(dfs(0 , get_first(a , b) , a , b)){
            ok = 1;
            break;
        }
    }
    if(ok){
        printf("Case %d: " , ++counter);
        printf("%d/%d=" , a , b);
        for(int i = 0 ; i <= maxd ; i ++){
            printf(i == maxd ?"1/%lld":"1/%lld+", ans[i]);
        }
    }
    }
    return 0;
}