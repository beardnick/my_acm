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

int vis[15];
int size(int a){
    int j = 0 ;
    for(int i = 1 ; i <= a ; i *= 10){
        j ++;
    }
    return j;
}

int create(int beg , int end){
    int a = 0;
    for(int i = beg ; i < end ; i ++){
        a = a * 10 + vis[i];
    }
    return a;
}
int main(){
    int n , a , b , c , tot;
    while(scanf("%d" , &n) != EOF){
    for(int i = 0 ; i <= 8 ; i ++){
        vis[i] = i + 1;
    }
        tot = 0;
        do{
            for(int i = 1 ; i <= size(n) ; i ++){
                for(int j = i + 1 ; j <= 8 ; j ++){
                    a = create(0 , i);
                    b = create(i , j );
                    c = create(j , 9);
                    if((n - a) * c == b){
                        tot ++;
//                        printf("%d = %d + %d / %d\n" , n , a , b , c);
                    }
                }
            }
        }while(next_permutation(vis , vis + 9));
        cout<<tot<<endl;
    }
    return 0;
}
