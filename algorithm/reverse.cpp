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

string  reverse(string s){
    if(s.length() > 1 ){
        int len = s.length();
        s = reverse(s.substr(len / 2 , len - len / 2))
            + reverse(s.substr(0 , len / 2));
    }
    return s;
}
int main(){
    string s;
    while(cin>>s){
        cout<<reverse(s)<<endl;
    }
    return 0;
}
