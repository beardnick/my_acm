#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;
int h , w , n;
int MAX[maxn<<2];
void PushUP(int rt) {
    MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
}
void build(int l,int r,int rt) {
    MAX[rt] = w;
    if (l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
int query(int x,int l,int r,int rt) {
    if (l == r) {
        MAX[rt] -= x;
        return l;
    }
    int m = (l + r) >> 1;
    int ret = (MAX[rt<<1] >= x) ? query(x , lson) : query(x , rson);
    PushUP(rt);
    return ret;
}
int main() {
    while (~scanf("%d%d%d",&h,&w,&n)) {
        if (h > n) h = n;
        build(1 , h , 1);
        while (n --) {
            int x;
            scanf("%d",&x);
            if (MAX[1] < x) puts("-1");
            else printf("%d\n",query(x , 1 , h , 1));
        }
    }
    return 0;
}
