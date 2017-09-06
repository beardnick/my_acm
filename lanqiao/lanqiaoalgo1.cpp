#include<iostream>
#include<algorithm>
using namespace std;
#define M 1000
bool cmp(int a,int b)
{
    return a>b;
}
int a[M],b[M];
int main()
{
      int n,k,l,r,m;
      cin>>n;
     for(int i=0;i<n;i++)
         cin>>a[i];
        cin>>m;
        while(m--)
        {
            for(int i=0;i<n;i++)b[i]=a[i];
            cin>>l>>r>>k;
            sort(b+l-1,b+r,cmp);
            cout<<b[l+k-2]<<endl;
        }
     return 0;
}
