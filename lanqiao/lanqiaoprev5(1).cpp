#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
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
    for(int i=0;i<=j;i++)b[a[i]]++;
    for(int i=0;!(b[i]>0&&b[i+1]==0&&b[i+2]==0);i++)
        {
            if(b[i]==0&&b[i-1]>0&&b[i+1]>0)m=i;
            if(b[i]==2)n=i;
        }
    printf("%d %d\n",m,n);
    return 0;
}
