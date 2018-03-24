#include<cstdio>
#include<set>
#include<iostream>

using namespace std;

const long MAXSUM = 98765;
int isDiff(long value , long n){
    set<long>s;
    long mod = 1;
    long temp;
    for(long i = 1 ; i <= n; i ++){
      temp = value % (mod * 10);
      s.insert(temp / mod);
      mod *= 10;
    }
    return s.size() == n;
}

int isDiff(long value1 , long value2 , long n1 , long n2){
    set<long>s;
    long mod = 1;
    long temp;
    for(long  i = 1 ; i <= n1; i ++){
      temp = value1% (mod * 10);
      s.insert(temp / mod);
      mod *= 10;
    }
    mod = 1;
     for(long  i = 1 ; i <= n2; i ++){
      temp = value2% (mod * 10);
      s.insert(temp / mod);
      mod *= 10;
    }
    return s.size() == (n1 + n2);
}

int main(){
    long n;
    int has;
    int k = 0 ;
    while(scanf("%d" , &n) == 1 && n){
            has = 0;
            if(k)printf("\n");
            k ++;
        for(long i = 1234 ; i < 54321 ; i ++){
        if(i * n <  MAXSUM && isDiff(i , 5) && isDiff(i*n , i  ,  5 , 5 )){
            printf("%05ld / %05ld = %ld\n" , i * n , i , n);
            has = 1;
        }
    }
    if(has == 0){
        printf("There are no solutions for %ld.\n" ,n );
    }
    }
    return 0;
}
