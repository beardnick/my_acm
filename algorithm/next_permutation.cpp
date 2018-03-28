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
const int N = 4;
int main(){
    int a[MAXN];
    for(int i = 1 ; i <= N ; i ++){
        a[i -1] = i;
    }
    do{
        for(int i = 0 ; i < N  ; i ++){
            cout<<a[i];
        }
        cout<<endl;
    }while(next_permutation(a , a + N));
    return 0;
}
