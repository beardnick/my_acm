#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;

    while(cin>>s)
    {
        long long n=0;
        for(int i=0;s[i]!='\0';i++)
        {
            n+=(s[i]-'0');//大数处理
        }
//        long long sum=0;
//             for(sum=0;!(n>0&&n<10);n=sum,sum=0)
//        {
//            while(n)
//            {
//                sum+=n%10;
//                n/=10;
//            }
//        }
    if(0==n)return 0;
    int t=n%9;
    if(!t)cout<<9<<endl;
     else cout<<t<<endl;//九余数定理
    }
    return 0;
}
