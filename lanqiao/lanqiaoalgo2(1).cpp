#include<iostream>
using namespace std;
int main(){
    long long ans, n;

    while(cin >> n){
            if(n<=2){
                ans = n;
            }
            else if(n%2){
                ans = n*(n-1)*(n-2);
            }
            else {
                if(n%3){
                    ans = n*(n-1)*(n-3);
                }
                else ans = (n-3)*(n-1)*(n-2);
            }
            cout<<ans<<endl;
    }
    return 0;
}
