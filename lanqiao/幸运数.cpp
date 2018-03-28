#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<list>

using namespace std;
const int INF = (1 << 30);
const int MAXN = 1000010;

int main(){
    int temp;
    list<int> l;
    list<int>::iterator it;
    for(int i = 1 ; i <= MAXN ; i += 2){
        l.push_back(i);
    }
    list<int>::iterator beg = l.begin();
    advance(beg , 1);
    for(list<int>::iterator it = beg  ; it != l.end() ; it ++){
        temp = *it;
        printf(", %d" , temp);
        beg = l.begin();
        advance(beg , temp - 1);
        for(list<int>::iterator jt = beg; jt != l.end() ; advance(jt , temp -1)){
//            printf("L%d>>%derase\n" , distance(l.begin() , jt) + 1 , *jt);
            jt = l.erase(jt);
            if(distance(jt , l.end()) < temp - 1 ){
                break;
            }
        }
    }
    return 0;
}
