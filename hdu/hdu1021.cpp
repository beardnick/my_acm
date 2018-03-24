//#include<iostream>
//using namespace std;
//#define N 1000
//int f[N];
//int main()
//{
//    int n,flag;
//    cin>>n;
//    f[0]=7;
//    f[1]=11;
//    for(int i=2;i<=n;i++)
//    {
//        f[i]=f[i-1]+f[i-2];
//        if(f[i]%3==0)flag=1;
//        else flag=0;
//        cout<<i<<' '<<f[i]<<' '<<flag<<endl;
//    }
//    return 0;
//
//}
#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if((n+2)%4==0)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
