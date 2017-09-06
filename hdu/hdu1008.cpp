#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    vector<int> s;
    while(cin>>n&&n)
    {
        int sum=0,a;
        s.clear();
       for(int i=0;i<n;i++)
        {
            cin>>a;
            s.push_back(a);
            if(i==0)sum+=(6*s[i]);
            else if(s[i]>s[i-1])sum+=((s[i]-s[i-1])*6);
            else if(s[i]<s[i-1])sum+=((s[i-1]-s[i])*4);
        }
        sum+=(n*5);cout<<s.size()<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
