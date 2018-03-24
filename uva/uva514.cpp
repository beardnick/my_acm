#include<cstdio>
#include<stack>

using namespace std;

const int maxn = 1010;

int main(){
    int n , target[maxn] , queue , counter;
    stack<int>s;
    while(scanf("%d" , &n) && n !=0){
            while(1
                  ){
                    scanf("%d" , &target[1]);
                    if(target[1] == 0){
                printf("\n");
                break;
        }
                for( int i = 2 ; i <= n ; i ++){
                scanf("%d" , &target[i]);
        }
        queue = 1;
        counter = 1;
        while( ! s.empty()){
            s.pop();
        }
        while(queue <= n + 1){
            if(queue == target[counter]){
                counter ++;
                queue ++;
            }else if(! s.empty() && s.top() == target[counter]){
                     counter ++;
                    s.pop();
            }else{
                    s.push(queue);
                    queue ++;
            }
        }
        printf("%s\n" , counter > n ? "Yes" : "No");
            }
    }

}
