#include<iostream>
using namespace std;
int main()
{
    long long n;
    while(cin>>n&&n)
    {
        long long sum=0;
             for(sum=0;!(n>0&&n<10);n=sum,sum=0,cout<<n<<endl)
        {
            while(n)
            {
                sum+=n%10;
                n/=10;
            }
        }
     cout<<n<<endl;
    }
    return 0;
}
