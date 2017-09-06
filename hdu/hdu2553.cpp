#include<iostream>
using namespace std;
int tot=0,a[15],n;
void eightqueen(int cur)
{
    if(cur==n)tot++;
    else
    {
        for(int i=0;i<n;i++)
        {
            int ok=1;
            a[cur]=i;
            for(int j=0;j<cur;j++)
            {
                if(a[cur]==a[j]||cur-a[cur]==j-a[j]||cur+a[cur]==j+a[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)eightqueen(cur+1);
        }
    }
}
int main()
{
    while(cin>>n&&n)
        {
            tot=0;
            eightqueen(0);
            cout<<tot<<endl;
        }
        return 0;
}
