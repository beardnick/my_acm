#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int main()
{
    int c;
    cin>>c;
    for(int i=1;i<=c;i++)
    {
        int n,thissum,maxsum;
        cin>>n;
        for(int j=1;j<=n;j++)
            cin>>a[j];
            thissum=maxsum=a[1];
        for(int j=1;j<=n;j++)
           {
               if(a[j]>=0)thissum+=a[j];
               else {maxsum=max(maxsum,thissum);thissum=0;}
           }
           cout<<maxsum<<endl;
    }
    return 0;
}
