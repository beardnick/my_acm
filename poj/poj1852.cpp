#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int main()
{
    int n,l,cas;
    cin>>cas;
    while(cas--)
    {
        a.clear();
        int summin=0,summax=0;
        cin>>l>>n;
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            a.push_back(t);
        }
        for(int i=0;i<n;i++)
        {
            summin=max(summin,min(a[i],l-a[i]));
            summax=max(summax,max(a[i],l-a[i]));
        }
        cout<<summin<<' '<<summax<<endl;
    }
    return 0;
}
