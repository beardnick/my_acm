#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

const int MAXM = 15;
const int MAXN = 110;
const int INF = (1 << 30);
int m , n , a[MAXN][MAXM] , d[MAXN][MAXM] , nextr[MAXN][MAXM];
int temp[3];

//特殊情况，多行一列的时候

int dp(int x , int y){
	if(x == n){
		// printf("(%d , %d)>>%d\n" , x , y , a[x][y]);
		d[x][y] = a[x][y];
		return a[x][y];
	}
	int& ans = d[x][y];
	if(ans != INF){
		// printf("(%d , %d)>>%d\n" , x , y , ans);
		return ans;
	}
	int rows[3] = {y - 1, y , y + 1};
	if(rows[0] < 1)rows[0] = m;
    if(rows[2] > m)rows[2] = 1;
    sort(rows , rows + 3);
	for(int i = 0 ; i <= 2 ; i ++){
		int temp = dp(x + 1 , rows[i]) + a[x][y];
		if(temp < ans){
			ans = temp;
			nextr[x][y] = rows[i];
		}
	}
	// printf("(%d , %d)>>%d\n" , x , y , ans);
	return ans;
}

int main(){
	while(scanf("%d%d" , &m , &n) != EOF){
		for(int i = 1 ;i <= m; i ++){
		for(int j = 1 ; j <= n; j ++){
			scanf("%d" , &a[j][i]);
			d[j][i] = INF;
		    }
		}
		// for(int i = 1 ;i <= m; i ++){
		// for(int j = 1 ; j <= n; j ++){
			// printf("%d " , a[j][i]);
		    // }
			// printf("\n");
		// }
		int minres = INF , first = 1;
		for(int i = 1 ; i <= m ; i ++){
			// cout<<endl<<endl<<endl;
			int temp = dp(1 , i);
			if(temp < minres){
				minres = temp;
				first = i;
			}
		}
		printf("%d" , first);
		for(int i = 1 , j = first; i < n ;j = nextr[i][j] , i ++){
			printf(" %d" , nextr[i][j]);
		}
		cout<<endl<<d[1][first]<<endl;
		
	}
	return 0;
}

/* 
5 6
8 4 1 3 2 6
3 7 2 8 6 4
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
 */