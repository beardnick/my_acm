#include<iostream>
using namespace std;
int C[100],tot=0,n;
void search(int cur)

{
    if(cur==n)
    {
        tot++;
        cout<<"(";
        for(int i=0;i<n;i++)
        {
            if(i==0)cout<<C[i]+1;
            else cout<<","<<C[i]+1;
        }
        cout<<")"<<tot<<endl;
    }
    else for(int i=0;i<n;i++)
    {
        int ok=1;
        C[cur]=i;
        for(int j=0;j<cur;j++)
            if(C[cur]==C[j])
        {
            ok=0;break;
        }
        if(ok)search(cur+1);
    }
}
int main()
{
    cin>>n;
    search(0);
    return 0;
}
