#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int n,num[10010];
    while(cin>>n&&n)
    {
        int thissum=0,maxsum=-1,beg=0,end=0,temp=0,pos=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            thissum+=num[i];
            //cout<<thissum<<' '<<maxsum<<' '<<beg<<' '<<end<<endl;
            if(num[i]>=0)pos=1;
            if(thissum>maxsum){maxsum=thissum;end=i;beg=temp;}
            if(thissum<0){thissum=0;temp=i+1;}
        }
        if(pos)cout<<maxsum<<' '<<num[beg]<<' '<<num[end]<<endl;
        else cout<<0<<' '<<num[0]<<' '<<num[n-1]<<endl;
    }
    return 0;
}
