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
int n , k;

struct node{
    int w , h;
    int operator < (node& n){
        return n.w < w;
    }
};
node a[MAXN];

int bin(int ma , int mi){
    if(ma - mi < 2){
        return mi;
    }
    int sum = 0;
    int m = (ma + mi) / 2;
    for(int i = 0 ;i < n && a[i].w >= m ; i ++){
        sum += ((a[i].w / m) * (a[i].h / m));
    }
    if(sum > k){
        return bin(ma , m);
    }else if(sum < k){
        return bin(m , mi);
    }else{
        return m;
    }
}
int main(){
    int w , h ;
    while(scanf("%d%d" , &n , &k) != EOF){
        for(int i = 0 ; i < n ;i ++){
            scanf("%d%d" , &h , &w);
            if(w > h){
                swap(w , h);
            }
            a[i].w = w;
            a[i].h = h;
        }
        sort(a , a + n);
        cout<<bin(a[0].w , 1)<<endl;
    }
    return 0;
}
