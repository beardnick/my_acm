#include<iostream> #include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 60000;
const int INF = - (1<<30);
int n , d[MAXN] , v[MAXN];
int find_max(int s){ int& ans = d[s];
	if(ans != -1){ return ans; } ans = INF;
	for(int i = 0 ;i < n; i ++){
		if(s >= v[i]){
			ans = max(ans , find_max(s - v[i]) + 1);
		}
	}
	return ans;
}
int find_min(int s){
	int& ans = d[s];
	if(ans != -1){
		return ans;
	}
	ans = -INF;
	for(int i = 0 ; i < n; i ++){
		if(s >= v[i]){
			ans = min(ans , find_min(s - v[i]) + 1);
		}
	}
	return ans;
}
int main(){
	int s;
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; i ++){ 
		scanf("%d" , &v[i]);
	}
	while(scanf("%d" , &s) != EOF){
		int temp; cout<<"max>>";
		memset(d , -1 , sizeof(d));
		d[0] = 0; temp = find_max(s);
		if(temp >= 0){ cout<<temp<<endl;
		}else{
			cout<<"impossible"<<endl; 
		} //cout<<(temp >= 0 ? temp : "impossible")<<endl;
		cout<<"min>>"; memset(d , -1 , sizeof(d));
		d[0] = 0;
		temp = find_min(s);
		if(temp < -INF){
			cout<<temp<<endl;
		}else{
			cout<<"impossible"<<endl;
		} //cout<<(temp < -INF ? temp : "impossible")<<endl; }
	return 0;
} 
