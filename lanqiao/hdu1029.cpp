#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>a;
    int n;
    while(cin>>n)
    {
        a.clear();
        for(int i=1;i<=n;i++)
            {
                int t;
                cin>>t;
                a.push_back(t);
            }
        sort(a.begin(),a.end());
        cout<<a[(a.size()+1)/2]<<endl;
    }
    return 0;
}
