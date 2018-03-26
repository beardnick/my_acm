#include<iostream>
#include<cstdio>

using namespace std;

int  f(long long n){
    long long x = 1;
    for(int i = 0 ; i <= 63 ; i ++){
        if((x << i) >= n){
            return i;
        }
    }
}

int main(){
    int n;
    scanf("%d" , &n);
    while(n --){
        long long x;
        scanf("%lld" , &x);
        cout<<f(x)<<endl;
    }
    return 0;
}
