#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxd=20;
int  s[1<<maxd];
int main()
{
    int  d,i;
    while(cin>>d>>i)
    {
        memset(s,0,sizeof(s));
        int k,n=(1<<d)-1;
        for(int j=0;j<i;j++)
        {
            k=1;
            for(;;)
            {
                s[k]=!s[k];
                k=s[k]?k*2:k*2+1;
                if(k>n)break;
            }
        }
        cout<<k/2<<endl;
    }
    return 0;
}
