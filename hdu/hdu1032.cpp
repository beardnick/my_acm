#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int>a;
int findit(int x)
{
    int t;
    if(x%2==0)t=x/2;
    else t=3*x+1;
    for(int i=a.size()-1;i>=0;i--)
    if(a[i]==t)return a.size()-i+1;
}
int main()
{
    int x,y;

   int n=1000000;
        while(n!=1)
    {
        if(n%2==0)n/=2;
        else n=3*n+1;
        a.push_back(n);
    }
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<' ';
    cout<<endl;
    while(cin>>x>>y)
    {
      int max=1,maxn=1;
      for(int i=x;i<=y;i++)
      {
          if((maxn=findit(i))>max)max=maxn;
          cout<<maxn<<endl;
      }

    printf("%d %d %d\n",x,y,max);
    }
    return 0;
}
