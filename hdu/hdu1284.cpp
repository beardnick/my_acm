#include<iostream>
using namespace std;
int tot=0;
void try(int x)
{
    if(x==0)tot++;
    else
    {
        for(int i=1;i<=3;i++)
            try(x-i);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        tot=0;
        try(n);
        cout<<tot<<endl;
    }
    return 0;
}
