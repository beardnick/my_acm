#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    int n,counter=0;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int i=0,j=0;j<n;i++,j++)
        if(a[i]==0)
        {
             a.erase(a.begin()+i,a.begin()+i+1);
             i--;
        }
    if(a.empty())
    {
        cout<<0;
    }
    else
    {
        cout<<a.size()<<endl;
    cout<<a[0];
    for(int i=1;i<a.size();i++)
        printf(" %d",a[i]);
    }
    return 0;
}
