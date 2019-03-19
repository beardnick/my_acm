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

void flush(string& s , stack<string>& st){
    if(s.length()){
        st.push(s);
        s = "";
    }
}

int calc(string s){
    stack<char> chars ;
    stack<string> nums;
    string num;
    string a , b;
    for(int i = 0 ; i < s.length() ; i ++){
        switch(s[i]){
            case '(':
                flush(num , nums);
                chars.push(s[i]);
                break;
            case 'x':
                num += 'x';
                break;
            case '|':
                flush(num , nums);
                break;
            case ')':
                flush(num , nums);
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                chars.pop();
                num = a.length() > b.length() ? a : b;
                if(chars.empty() && ! nums.empty()){
                    num += nums.top();
                    nums.pop();
                }
                break;
            default:
                cout<<num<<endl;
                break;
        }
//        cout<<num<<endl;
    }
    if(! nums.empty()){
        a = nums.top();
        num = num.length() > a.length() ? num : a;
    }
    return num.length();
}
int main(){
    string s;
    while(cin>>s){
//        cout<<s<<endl;
        cout<<calc(s)<<endl;
    }
    return 0;
}
