#include<cstdio>
#include<cmath>

using namespace std;


const int MAXN = 17;
int a[MAXN]  , n , counter = 0;

int is_prime(int value){
    int flag = 1;
    for(int i = 2;i <= sqrt(value) ; i ++){
        if(value % i == 0)flag = 0;
    }
    return flag;
}

void prime_circle(int cur){
    if(cur == n){
        for(int i = 0 ;i < n -1; i ++){
            printf("%d " , a[i]);
        }
        printf("%d" , a[n -1 ]);
        printf("\n");
    }else{
        for(int i = 2 ;i <= n ;i ++){
                int ok = 1;
            for(int j = 0 ; j < cur ;j ++){
                if(a[j] == i){
                    ok = 0;
                    break;
                }
            }
            if(ok && is_prime(a[cur - 1] + i)){
                    if(cur == n - 1 && ! is_prime(1 + i))break;
                a[cur] = i;
                prime_circle(cur + 1);
            }
        }
    }
}

int main(){
    while(scanf("%d" , &n) != -1 && n){
        if(counter)printf("\n");
        a[0] = 1;
        printf("Case %d:\n" , ++counter);            a[0] = 1;
        prime_circle(1);
    }
}
