#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

const int INF = 60000;

int main(){
    string line;
    
    
    
    while(getline(cin , line)){
        cout<<line<<endl;
        stringstream ss(line);
        deque<int> q;
        int x;
        while(ss >> x)q.push_front(x);
        for(deque<int>::iterator it = q.begin() ; it != q.end() ; it ++){
            deque<int>::iterator i = max_element(it , q.end());
            if(i != it){
                if(i != q.end() - 1){
                    cout<<distance(q.begin() , i) + 1<<' ';
                    reverse(i , q.end());
                }
                cout<<distance(q.begin() , it) + 1<<' ';
                reverse(it , q.end());
            }
        }
        cout<<"0"<<endl;
    }
    return 0;
}