#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int INF = (1<<16);
int vis[INF];

int main(){
    int n;
    while(scanf("%d" , &n) != EOF){
    memset(vis , 0 , sizeof(vis));
    for(int i = 2 ; i <= n ; i ++){
        for(int j = i * 2 ; j <= n ; j += i){
            vis[j] = 1;
        }
    }
    for(int i = 1 ; i <= n ; i ++){
        if(! vis[i]){
            printf("%d " , i);
        }
    }
    cout<<endl;
    }
    return 0;
}
