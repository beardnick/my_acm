#include<cstdio>
#include<list>
#include<stack>
#include<cstring>

using namespace std;

const int maxn = 100010;

int main(){
    enum flag{h , e};
    flag f = e;
    char s[maxn];
    while(scanf("%s" , s + 1) == 1){
            list<char> ls;
            list<char>::iterator it;
            int n = strlen(s + 1);
            stack<char>temp;
            char ch;
        for( int i = 1 ; i <= n ; i ++){
            ch = s[i];
            if(ch == '['){
                while(! temp.empty()){
                        ls.push_front(temp.top());
                        temp.pop();
                    }
                f = h;
            }else if( ch == ']'){
                while(! temp.empty()){
                        ls.push_front(temp.top());
                        temp.pop();
                    }
                f = e;
            }else  {
                if(f == h){
                    temp.push(ch);
                }else if(f == e){
                    ls.push_back(ch);
                }
            }
        }
 while(! temp.empty()){
                        ls.push_front(temp.top());
                        temp.pop();
                    }
        for(it = ls.begin(); it != ls.end() ; it ++){
            printf("%c" , *it);
        }
        printf("\n");
    }
    return 0;
}
