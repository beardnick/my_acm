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

int i;
string s;
string calc(){
    string res;
    string nums[2];
    int cur = 0;
    for(; i < s.length() && res.length() == 0 ; i ++ ){
        switch(s[i]){
        case '(':
            i ++;
            nums[cur] += calc();
            break;
        case '|':
            cur = 1;
            break;
        case 'x':
            nums[cur] += 'x';
            break;
        case ')':
            res = nums[0].length() > nums[1].length()? nums[0] : nums[1];
            i --;
            break;
        }
//        cout<<nums[cur]<<endl;
    }
    if(res.length() == 0){
        res = nums[0].length() > nums[1].length()? nums[0] : nums[1];
    }
    return res;
}
int main(){
    while(cin>>s){
        i = 0;
        cout<<calc().length()<<endl;
    }
    return 0;
}
