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

void ex_gcd(int a , int b , int& x ,int& y){
    if(a < b){
        int t = a;
        a = b;
        b = t;
    }
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    int x1 , y1;
    ex_gcd(b , a % b , x1 , y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
int main(){
    int x  , y ;
    ex_gcd(7 , 4 , x , y);
    printf("x>>%d , y>>%d\n" , x , y);
    return 0;
}
