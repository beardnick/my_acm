#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a , b;
int search(int l , int r , int k){
    b.clear();
    b.push_back(0);
    for(int i = l ; i <= r ; i ++ ){
        b.push_back(a[i]);
    }
    sort( b.begin() + 1 , b.end());
    return b[r - l + 1 - k + 1];
}
int main(){
    a.push_back(0);
    int m , n , l , r , k;
    int temp;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d" , &temp);
        a.push_back(temp);
    }
    scanf("%d" , &m);
    while(m --){
        scanf("%d%d%d" , &l , &r , &k);
        cout<<search(l , r , k)<<endl;
    }
    return 0;
}
