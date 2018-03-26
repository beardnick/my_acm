#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 100010;
int sum[MAXN<<2] , maxn[MAXN<<2] , a[MAXN];

void push_up(int index){
    sum[index] = sum[2 * index] + sum[2 * index + 1];
    maxn[index] = max(maxn[2 * index] , maxn[2 * index + 1]);
}

void build(int l , int r , int index){
    if(l == r){
        sum[index] = a[l];
        maxn[index] = a[l];
        return;
    }
    int m = (r + l) / 2;
    build(l , m ,2 * index );
    build(m + 1 , r , 2 * index + 1 );
    push_up(index);
}

void update(int l , int r , int p, int c , int index){
    if(l == r){
        sum[index] += c;
        maxn[index] += c;
        return;
    }
    int m = (l + r) / 2;
    if(p <= m){
        update(l , m , p , c , index * 2);
    }else{
        update(m + 1 , r , p , c , index * 2 + 1);
    }
    push_up(index);
}
int query_sum(int b , int e , int l , int r , int index){
    int m = (l + r) / 2;
    if(b == l && e == r){
        return sum[index];
    }else if(e <= m){
        return query_sum(b , e , l , m , index * 2);
    }else if(b >= m + 1){
        return query_sum(b , e , m + 1 , r , index * 2 + 1);
    }else{
        return query_sum(b , m , l , m , index *2) + query_sum(m + 1 , e , m + 1 , r , index * 2 + 1);
    }
}

int query_maxn(int b , int e , int l , int r , int index){
    int m = (l + r) / 2;
    if(b == l && e == r){
        return maxn[index];
    }else if(e <= m){
        return query_maxn(b , e , l , m , index * 2);
    }else if(b >= m + 1){
        return query_maxn(b , e , m + 1 , r , index * 2 + 1);
    }else{
        return max(query_maxn(b , m , l , m , index *2),  query_maxn(m + 1 , e , m + 1 , r , index * 2 + 1));
    }
}

int main(){
    int n , m , p , x , y;
    while(scanf("%d%d" , &n ,&m) != EOF){
        for(int i = 1 ; i <= n ; i ++){
            scanf("%d" , &a[i]);
        }
        build(1 , n , 1);
        while(m --){
            int p , x , y;
            scanf("%d%d%d" , &p , &x , &y);
            switch(p){
                case 1:
                    update(1 , n , x , y -a[x] , 1);
                    a[x] = y;
                    break;
                case 2:
                    cout<<query_sum(x , y , 1 , n , 1)<<endl;
                    break;
                case 3:
                    cout<<query_maxn(x , y , 1 , n , 1)<<endl;
                    break;
            }
        }
    }
    return 0;
}
