#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,n,t;
    cin>>t;
    while(t--)
    {
        int counter1=0;
        while(cin>>n>>m&&n)
        {
            int counter=0;
        for(double i=1;i<n;i++)
            for(double j=i+1;j<n;j++)
                if(((i*i+j*j+m)/(i*j))>0&&(int)(i*i+j*j+m)%(int)(i*j)==0)counter++;
        printf("Case %d: %d\n",++counter1,counter);
        }
        if(t>0)cout<<endl;
    }
    return 0;
}
