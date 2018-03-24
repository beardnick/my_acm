#include<iostream>
#include<cstdio>

using namespace std;

const int BEG = 65;
const int MAXN = 81;

int l , n;
int prior , counter = 0;
int s[MAXN];

int hard_string(int cur){
    if(counter == n){
        for(int i = 0 ;i < cur ; i ++){
              if(i == 64){printf("\n");}
              else if(i&&i % 4 == 0){printf(" ");}
            printf("%c" , s[i] + BEG);
        }
        printf("\n%d\n" , cur);
        return 0;
    }
        for(int i = 0 ; i < l; i ++){
        int ok = 1;
        s[cur] = i;
        for(int j = 1; j * 2<= cur + 1; j ++){
                int equal = 1;
            for(int k = 0 ; k <= j - 1; k ++){
                if(s[cur - k] != s[cur - j - k] ){
                    equal = 0;
                    break;
                }
            }
            if(equal){
                ok = 0;
                break;
            }
        }
        if(ok){
            counter ++;
            if( ! hard_string(cur + 1)){return 0;}
        }
    }
    return 1;
}

int main(){
    while(scanf("%d%d" , &n , &l) &&n &&l){
        counter = 0;
        hard_string(0);
    }
    return 0;
}
