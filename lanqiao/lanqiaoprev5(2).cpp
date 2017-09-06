#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10020
int a[N],b[N];
int main()
{
    int c,j=0;
    string line;
    cin>>c;
    getchar();
    while(c--)
    {
        getline(cin,line);
        stringstream ss(line);
        for(;(ss>>a[j]);j++);
    }
    j--;
    int m,n;
    sort(a,a+j+1);
    for(int i=0;i<j;i++)
    {
        if(0==a[i+1]-a[i])n=a[i];
        if(2==a[i+1]-a[i])m=a[i]+1;
    }
    printf("%d %d\n",m,n);
    return 0;
}
