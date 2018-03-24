#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1000;

struct rectangle{
    int width , height;
};


rectangle rectangles[MAXN];
int graph[MAXN][MAXN] , d[MAXN] , n;

int dp(int i){
    int& ans = d[i];
    if(ans > 0)return ans;
    ans = 1;
    for(int j = 0 ; j < n ; j ++){
        //因为graph[i][j] 和 graph[j][i]不可能同时为1 ， 所以不会出现dp(i)
        //依赖dp(j) , dp(j) 又依赖于 dp(i)的现象，所以递归不会出现死循环
        if(graph[i][j]) ans = max(ans , dp(j) + 1);
    }
    return ans;
}

void print_ans(int i){
    // printf("%d " , i + 1);
   printf("(%d , %d) " , rectangles[i].width , rectangles[i].height);
    for(int j = 0 ; j < n ; j ++){
        if(graph[i][j] && d[i] == d[j] + 1){
            print_ans(j);
            break;
        }
    }
}

int main(){
    while(scanf("%d" , &n) != EOF && n){
        for(int i = 0 ; i < n ; i ++){
            scanf("%d%d" , &rectangles[i].height , &rectangles[i].width);
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if( (rectangles[i].width < rectangles[j].width && rectangles[i].height < rectangles[j].height) || (rectangles[i].width < rectangles[j].height && rectangles[i].height < rectangles[j].width) ){
                    graph[i][j] = 1;
                }else{
                    graph[i][j] = 0;
                }
            }
        }
        memset(d , 0 , sizeof(d));
        dp(0);
        int temp = -1 , k;
        for(int i = 0 ; i < n ; i ++){
            if(d[i] > temp){
                temp = d[i];
                k = i;
            }
        }
        print_ans(k);
        printf("\n");
    }
    return 0;
}