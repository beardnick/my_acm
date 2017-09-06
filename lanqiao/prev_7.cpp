#include<iostream>
#include<algorithm>
#include<cstdio>
using  namespace std;
int a[50010];
int main()
{
    int n;
    while(cin>>n)
    {
        int tot=0;
        int maxn,minn;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
            maxn=minn=a[i];
            for(int j=i+1;j<n;j++)
            {
                maxn=max(maxn,a[j]);
                minn=min(minn,a[j]);
                if(maxn-minn==j-i)tot++;
        }

    }
    cout<<tot+n<<endl;
    }
    return 0;
}
