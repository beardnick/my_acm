#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXN = 10000;
int a[MAXN] ,b[MAXN];
int d[MAXN][MAXN] , m , n;
queue<int>q;

void lcs(){
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if(b[i] == a[j]){
				q.push(b[i]);
				d[i][j] = d[i - 1][j - 1] + 1;
			}else{
				d[i][j] = max(d[i-1][j] , d[i][j-1]);
			}
			// printf("d(%d , %d)>>%d\n" , i , j , d[i][j]);
		}
	}
}
int main(){
	while(scanf("%d%d" , &m , &n) != EOF){
		for(int i =  1 ; i <= m ; i ++){
			scanf("%d" , &a[i]);
		}
		for(int i = 1  ; i <= n ; i ++){
			scanf("%d" , &b[i]);
		}
		memset(d , 0 , sizeof(d));
		lcs();
		cout<<d[n][m]<<endl;
	}
	return 0;
}

/* 
6 7
1 5 2 6 8 7
2 3 5 6 9 8 4
*/