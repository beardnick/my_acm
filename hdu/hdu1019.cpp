#include<iostream>
#include<string>
#include<sstream>
using namespace std;
long long gcd(long long x,long long y)
{
    long long i;
    while(x&&y)
    {
        i=x%y;
        x=y;
        y=i;
    }
    return x;
}
long long lcm(long long x,long long y)
{
    return x/gcd(x,y)*y;
}
int main()
{
    long long n;
    cin>>n;
    while(n--)
    {
        long long a,b;
        long long m;
        cin>>m;
        cin>>a;
        m--;
        while(m--)
        {
            cin>>b;
            a=lcm(a,b);
        }
        cout<<a<<endl;
    }
    return 0;
}
