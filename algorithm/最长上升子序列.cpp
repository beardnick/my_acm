#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

const int INF = (1 << 30);
const int MAXN = 60000;
int d[MAXN] , a[MAXN] , n , path[MAXN];

void lis(){
	d[0] = 1;
	// int res = 1;
	for(int i = 1 ; i < n ; i ++){
		int temp = -INF;
		for(int j = 0 ; j < i ; j ++){
			if(a[j] < a[i] && d[j] > temp){
				temp = d[j];
				path[i] = j;
			}
		}
		d[i] = max(0 , temp) + 1;
		// printf("d[%d]>>%d\n" , i , d[i]);
		// res = max(res  , d[i]);
	}
	// return res;
}

int main(){
	while(scanf("%d" , &n) != EOF ){
		for(int i = 0 ; i < n; i ++){
			scanf("%d" , &a[i]);
		}
		stack<int>s;
		memset(d , -1 , sizeof(int) * (n + 10));
		memset(path , -1 , sizeof(int) * (n + 10));
		lis();
		//全是为了打印结果方便
		int res = -1 , resindex = 0;
		for(int i = 0 ; i < n ; i ++){
			if(d[i] > res){
				res = d[i];
				resindex = i;
			}
		}
		do{
			// printf("%d " , a[resindex]);
			s.push(a[resindex]);
			resindex = path[resindex];
		}while(resindex >= 0);
		while(! s.empty()){
			printf("%d " , s.top());
			s.pop();
		}
		cout<<endl<<res<<endl;
	}
	return 0;
}

/*
6
1 6 2 3 7 5 
12
1 7 3 6 4 7 9 10 2 9 8 5
*/